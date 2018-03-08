#include <vector>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

namespace Calc {

    class calc {

        public:
            bool analysis (string mathematical_str, vector < double > & num , vector < char > & opr);
            bool get_result (vector < double > num , vector < char > opr , double & result);

        private:
            string _str;
            int ctr;

    };
}
