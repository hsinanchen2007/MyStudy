### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return "";
        vector<int>cnt;
        vector<char>v;
        int num = 0;
        for(int i=0;i<s.size();++i)
        {
            // 字符的类型
            // 数字
            if(s[i]>='0'&&s[i]<='9')
            {
                num = num*10 + (s[i]-'0');
            }
            // 左括号
            else if(s[i]=='[')
            {
                v.push_back('[');
                cnt.push_back(num);
                num = 0;
            }
            // 右括号
            else if(s[i]==']'){
                string t = "";
                // 出栈直到遇见左括号
                while(v.back()!='[')
                {
                    char x = v.back();
                    t = x+t;
                    v.pop_back();
                }
                v.pop_back();
                // 这段字符要重复的次数
                int n = cnt.back();
                cnt.pop_back();
                while(n--)
                {
                    for(auto a:t)
                        v.push_back(a);
                }
            }
            // 字母
            else{
                v.push_back(s[i]);
            }
        }
        string ans = "";
        for(auto a:v)
            ans+=a;
        return ans;
    }
};
```