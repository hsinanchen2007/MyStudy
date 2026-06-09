### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // dfs、回溯、剪枝
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string tmp = "";
        backtrack(s, res, tmp, 0);
        return res;
    }
    // s：复原的ip字符串
    // res：保存复原结果的字符串数组
    // tmp：保存上一次递归的ip段，每一次递归都会把满足的ip拼上去
    // n：哪一段的ip段
    void backtrack(string s, vector<string>& res, string tmp, int n) {
        // 每段最多3个数字，复原ip字符串的字数过多不满足复原条件则return
        if(s.size() > 3*(4-n)) return ;
        // n==4而且字符串复原完毕
        if(n==4 && s.size()==0) {
            // 在字符串末尾删除一个字符
            tmp.pop_back();
            // 在容器末尾添加元素
            res.push_back(tmp);
        }
        for(int i=1; i<=3; i++) {
            if(s.size()<i) break;
            // 字符串转int
            int val = stoi(s.substr(0,i));
            // int转字符串，如果满足条件表示字符串以0开头
            if(i!=to_string(val).size()) break;
            if(val>255) break;
            tmp += s.substr(0,i)+'.';
            // 递归调用
            backtrack(s.substr(i),res,tmp,n+1);
            // tmp回溯
            tmp = tmp.substr(0,tmp.size()-i-1);
        }
    }
};



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(string s, vector<string>& res, string tmp, int n) {
    if (s.size() > 3*(4-n)) return ;
    if (n==4 && s.size()==0) {
        tmp.pop_back();
        res.push_back(tmp);
    }
    for(int i=1; i<=3; i++) {
        if (s.size()<i) break;
        int val = stoi(s.substr(0,i));
        if (i!=to_string(val).size()) break;
        if (val>255) break;
        tmp += s.substr(0,i)+'.';
        backtrack(s.substr(i),res,tmp,n+1);
        tmp = tmp.substr(0,tmp.size()-i-1);
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string tmp = "";
    backtrack(s, res, tmp, 0);
    return res;
}

int main() {
    vector<string> res = restoreIpAddresses("25525511135");
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
}





```