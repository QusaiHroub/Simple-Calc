#include "calc.hpp"

namespace Calc {

    bool calc::analysis(string mathematical_str, vector < double > & num , vector < char > & opr) {

        while (mathematical_str.size()) {
            if ((mathematical_str[0] >= '0' && mathematical_str[0] <= '9') || mathematical_str[0] == '.'){
                _str.push_back(mathematical_str[0]);
                mathematical_str.erase(mathematical_str.begin());
            } else if (mathematical_str[0]  == '+' || mathematical_str[0]  == '-' ||
                         mathematical_str[0]  == '*' || mathematical_str[0]  == '/' ||
                          mathematical_str[0]  == '^') {
                if (_str.empty())
                     num.push_back(0);
                else {
                    num.push_back(stof(_str));
                    _str.clear();
                }
                opr.push_back(mathematical_str[0]);
                mathematical_str.erase(mathematical_str.begin());
            } else if (mathematical_str[0] == '=') {
                if (_str.empty())
                     num.push_back(0);
                else {
                    num.push_back(stof(_str));
                    _str.clear();
                }
                mathematical_str.erase(mathematical_str.begin());
                if (!mathematical_str.empty()) {
                    while (mathematical_str.size()) {
                        if (mathematical_str[0] == ' ')
                            mathematical_str.erase(mathematical_str.begin());
                        else {
                            cout << endl << "\terror ... " << endl << endl;
                            return 0;
                        }
                    }
                }
                return 1;
            } else if (mathematical_str[0] == ' ') {
                mathematical_str.erase(mathematical_str.begin());
            } else {
                cout << endl << "\t" << mathematical_str[0] << " Unsupported symbol." << endl << endl;
                return 0;
            }
        }
        cout << endl << "\tsymbol \" = \" not found." << endl << endl;
        _str.clear();
        return 0;
    }

    bool calc::get_result (vector < double > num , vector < char > opr , double & result) {

        ctr = 0;
        while (ctr < int(opr.size())) {
            if (opr[ctr] == '^') {
                num[ctr] = pow(num[ctr],num[ctr + 1]);
                num.erase(num.begin() + ctr + 1);
                opr.erase(opr.begin() + ctr);
            } else
                ctr++;
        }
        ctr = 0;
        while (ctr < int(opr.size())) {
            if (opr[ctr] == '*') {
                num[ctr] *= num[ctr + 1];
                num.erase(num.begin() + ctr + 1);
                opr.erase(opr.begin() + ctr);
            } else if (opr[ctr] == '/') {
                if (num[ctr + 1]) {
                    num[ctr] /= num[ctr + 1];
                    num.erase(num.begin() + ctr + 1);
                    opr.erase(opr.begin() + ctr);
                } else {
                    cout << endl << "\tCan't divide by zero." << endl << endl;
                    return 0;
                }
            } else
                ctr++;
        }
        ctr = 0;
        while (ctr < int(opr.size())) {
            if (opr[ctr] == '+') {
                num[ctr] += num[ctr + 1];
                num.erase(num.begin() + ctr + 1);
                opr.erase(opr.begin() + ctr);
            } else if (opr[ctr] == '-') {
                num[ctr] -= num[ctr + 1];
                num.erase(num.begin() + ctr + 1);
                opr.erase(opr.begin() + ctr);
            } else
                ctr++;
        }
        result = num[0];

        return 1;
    }
}
