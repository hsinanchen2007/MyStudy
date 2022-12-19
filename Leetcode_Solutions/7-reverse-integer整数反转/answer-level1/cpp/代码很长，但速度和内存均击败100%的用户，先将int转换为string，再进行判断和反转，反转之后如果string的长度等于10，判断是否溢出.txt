class Solution {
public:
    int reverse(int x) {
        stringstream st;
        st << x;
        string str = st.str();
        string strRev(str.size(), ' ');
        if (x > 0 && x < 2147483648) {
            if (str.size() > 1 && str.back() == '0') {
                str = str.substr(0, str.size() - 1);
            }
            for (int i = 0; i < str.size(); i++) {
                strRev[i] = str[str.size() - 1 - i];
            }
            if (str.size()==10&&strRev>"2147483647") {
                return 0;
            }
            return stoi(strRev);
        }
        if (x < 0 && x >= -2147483647) {
            if (str.size() > 1 && str.front() == '-') {
                str = str.substr(1);
            }
            if (str.size() > 1 && str.back() == '0') {
                str = str.substr(0, str.size() - 1);
            }
            string strRev(str.size(), ' ');
            for (int i = 0; i < str.size(); i++) {
                strRev[i] = str[str.size() - 1 - i];
            }
            if (str.size() == 10 && strRev > "2147483647") {
                return 0;
            }
            return (-1)*stoi(strRev);
        }
        return 0;
    }
};