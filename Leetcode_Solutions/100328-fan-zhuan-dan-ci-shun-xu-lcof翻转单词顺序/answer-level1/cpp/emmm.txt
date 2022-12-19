### 解题思路
1. 首先清除左右两边的空格
2. 将所有的非空字符串加入到vector中
3. 从vector中最后一个非空格字符串开始遍历生成结果字符串

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vc;
        string ans = "";
        stringstream ss;
        // 清楚左右两边的字符串
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
        s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
        // 将非空字符串加入vector中，每加入一个字符串，再加入一个空格
        ss.str(s);
        string item;
        char delim= ' ';
        while(getline(ss, item, delim)){
            if(item != ""){
                vc.push_back(item);
                //加入一个空格
                vc.push_back(" ");
            }
        }
        // vc.size()-1处的空格是多余的，因此从vc.size()-2开始
        for(int i = vc.size()-2; i >= 0; i--) ans += vc[i];
        return ans;
    }
};
```