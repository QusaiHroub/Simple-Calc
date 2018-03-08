#include "calc.hpp"

using namespace Calc;
using namespace std;

int main ( ) {

    calc _calc;
    string m_str;
    cout << "Calc V : 0.0.1" << endl << endl
         << "--------------------------------------------------------------" << endl << endl
         << "You can use | + for Addition , - for Subtraction ,           |" << endl
         << "            | * for Multiplication , / for Division,         |" << endl
         << "            | ^ for Power , Every equation should end with = |" << endl
         << "            | Ctrl + D on Unix like OS or Ctrl + C to Exit.  |" << endl << endl
         << "--------------------------------------------------------------" << endl << endl ;
    while (cout << "Enter your equation : " &&
            getline(cin , m_str)) {

        vector < double > num ;
        vector < char > opr;
        double result;
        if (_calc.analysis(m_str, num , opr))
            if (_calc.get_result(num, opr ,result)) {
                cout << endl << '\t';
                for (int i = 0 ;i <= int(opr.size()); i++) {
                    cout << num[i];
                    if (i < int(opr.size()))
                        cout << " " << opr[i] << " ";
                }
                cout << " = " << result << endl << endl;
            }
    }

    return 0;
}
