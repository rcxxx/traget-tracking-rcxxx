#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string SAVE_IMG_PAHT = "/home/rcxxx/workspace/Program/QtProject/get-photo/img/";

int main()
{
    Mat src_img;

    VideoCapture cap(0);

    string classes;
    cout << "please enter the target name: ";
    cin >> classes;

    cout << endl << " set classes to " + classes<< endl;

    int img_order_num = 1;

    while (true) {

        cap >> src_img;

        stringstream _str;
        _str << SAVE_IMG_PAHT << classes << "-" << img_order_num <<".jpg";


        imshow("src_img", src_img);
        int key = waitKey(1);

        switch (key) {
        case 'P':
        case 'p':
        {
            /*------ save image ------*/
            string path = _str.str();
            imwrite(path, src_img);
            cout << "save img to " + path << endl;

            img_order_num += 1;

        } break;

        case 'C':
        case 'c':
        {
            /*------ change target classes ------*/
            cout << "please enter the new target name: ";
            cin >> classes;
            cout << endl << " set classes to " + classes<< endl;
            img_order_num = 1;

        } break;

        default:
            break;
        }


        if(static_cast<char>(key) == 27){
            break;
        }
    }

    return 0;
}
