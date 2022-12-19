string g_arr[31] = {"", "1", "11", "21", "1211", "111221"};
// 6---"312211"
using namespace std;
using uchar = unsigned char;
#define LOG(aaa) \
cout << aaa << endl;
class Solution {
public:
    string countAndSay(int n) {
        if ((n > 30) || (n < 1)) {
            return "";
        }
        if (!g_arr[n].empty()) {
            return g_arr[n];
        }
        for (int i = 6; i <= n; ) {
            if (!g_arr[i].empty()) {
                i++;
                continue;
            }
            g_arr[i] = cal(g_arr[i - 1]);
            i++;
        }
        return g_arr[n];
    }
    string cal(string& str) {
        if (str.empty()) {
            return "";
        }
        size_t pos = 0;
        uchar cur = str[0];
        string result;
        while(pos < str.size()) {
            cur = str[pos];
            size_t nextpos = findsamechar(str, pos);
            if (nextpos == pos) {
                result.append(1, '1');                
            } else {
               // LOG("Not same");
               // cout << "nextpos" << nextpos << "pos" << pos << endl;
                uchar tmpchar = '1';
                tmpchar += (uchar)(nextpos - pos);
                result.append(1, tmpchar);                
            }
            result.append(1, cur);
            pos = nextpos + 1;
        }
        return result;
    }
    size_t findsamechar(string& str, size_t begin) {
        size_t pos = begin;
        uchar cur = str[begin];
        for (int i = begin + 1; i < str.size(); i++) {
            if (i < str.size()) {
                if (str[i] == cur) {
                    pos = i;
                    continue;
                } else {
                    break;
                }
            }
        }
        return pos;
    }
};