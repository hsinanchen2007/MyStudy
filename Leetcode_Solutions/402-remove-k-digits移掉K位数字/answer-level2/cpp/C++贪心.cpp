从左往右遍历，如果第i个数字，比i+1大，那么删i而不删i+1可以使得数据最小








class Solution {
public:
    string removeKdigits(string num, int k) {
        // 不删除
        if (k <= 0) {
            return num;
        }

        // 全部删除
        int len = num.size();
        if (len == k) {
            return "0";
        }

        // 删除k个
        string tmp = num;
        for (int i = 0; i < k; i++) {
            // 从左往右，删连续的最大的那个数
            int tmpLen = tmp.size();

            // 只剩下最后一位，直接删除
            if (tmpLen <= 1) {
                tmp.erase();
                break;
            }

            bool del = false;
            for (int m = 0; m < tmpLen - 1; m++) {
                if (tmp[m] > tmp[m + 1]) {
                    // 删除第i个数字，比i+1大，删i可以使得数据最小
                    tmp.erase(m, 1);

                    del = true;
                    break;
                }
            }

            // 最后一个数字才是最大的，删最后一个
            if (del == false) {
                tmp.erase(tmpLen - 1, 1);
            }

            // 方式1去掉前导0
            // if ((!tmp.empty()) && (tmp[0] == '0')) {
            //     size_t m = 1;
            //     for (; m < tmp.size(); m++) {
            //         if (tmp[m] != '0') {
            //             break;
            //         }
            //     }

            //     if (m < tmp.size()) {
            //         tmp = tmp.substr(m);
            //     }
            //     else {
            //         tmp = "0";
            //         break;
            //     }
            // }

            // 去掉前导0方式2
            if ((!tmp.empty()) && (tmp[0] == '0')) {
                size_t notZero = tmp.find_first_not_of('0');
                if (notZero != string::npos) {
                    tmp = tmp.substr(notZero);
                } else {
                    tmp = "0";
                    break;
                }
            }

        }

        if (tmp.empty()) {
            return "0";
        } else {
            return tmp;
        }
    }
};