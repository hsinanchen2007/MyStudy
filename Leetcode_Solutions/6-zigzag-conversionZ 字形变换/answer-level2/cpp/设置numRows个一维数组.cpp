### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
string convert(string s, int numRows) {

    int len = s.size();
    if(len==0||len==1) return s;
    if(numRows==1) return s;
    int read_num = 2 * numRows - 2;//每轮读取2*numRows-2个数
    vector<char> val[numRows];//设置一个numRows行数组

//循环次数
    int time1 = len / read_num;
    int time2 = len % read_num;//剩下的数字
    cout << "read_num " << read_num << endl;
    cout << "time1  " << time1 << endl;
    cout << "time2  " << time2 << endl;

    for (int i = 0; i < time1; i++) {
        //存放完整字符串
        for (int j = 0; j < numRows; j++) {
            int loc = (read_num) * i + j;
            if (loc < len) {
                cout << " +" << s[loc] << ":" << j;
                val[j].push_back(s[loc]);
            }

        }
        int temploc = 0;
        for (int j = numRows - 2; j > 0; j--) {
//            cout<<
            int loc = read_num * i + numRows + temploc++;
            if (loc < len) {
                cout << " -" << s[loc] << ":" << j;
                val[j].push_back(s[loc]);
            }
        }
    }

    if (time2 != 0 && time2 <= numRows) {//完整一列
        cout << "小于" << endl;
        for (int j = 0; j < time2; j++) {
            int loc = time1 * read_num + j;
            if (loc < len) {
                cout << " +" << s[loc] << ":" << j;
                val[j].push_back(s[loc]);
            }
        }
    } else if (time2 != 0 && time2 > numRows) {
        cout << "大于" << endl;
        for (int j = 0; j < numRows; j++) {
            int loc = time1 * read_num + j;
            if (loc < len) {
                cout << " +" << s[loc] << ":" << j;
                val[j].push_back(s[loc]);
            }
        }
        int temploc = 0;
        int start = numRows - 2;
        for (int j = 0;j < (time2 - numRows); j++) {
            int loc = read_num * time1 + numRows + temploc++;
            if (loc < len) {
                cout << " -" << s[loc] << ":" << start;
                val[start--].push_back(s[loc]);
            }
        }
    }

    string ans;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < val[i].size(); j++) {
//            cout<<val[i][j]<<" ";
            ans += val[i][j];
        }
    }
    cout << endl << "PAYPGANLIIRSIH" << endl;
    return ans;
}

};
```