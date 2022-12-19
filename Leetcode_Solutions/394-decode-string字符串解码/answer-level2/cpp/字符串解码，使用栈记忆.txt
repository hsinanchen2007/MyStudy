### 解题思路
cur:当前字符串
cnt:重复次数
s_num:记录重复次数的栈
s_str:记录字符串前缀的栈

1.若碰到数字，更新重复次数
2.碰到'['，将当前字符串cur作为前缀进栈，重复次数cnt进栈，cnt=0,cur=""
3.碰到']'，根据s_num栈顶的重复次数k，当前字符串重复k次，并与其前缀(从栈取得)进行拼接，赋值给cur，出栈
4.碰到普通字符，更新cur

### 代码

```cpp
class Solution {
public:
    string decodeString(string s) {
        string cur = "";
        stack<string> s_str;
        stack<int> s_num;
        int cnt = 0;
        for(int i = 0;i < s.size();++i){
            if(s[i] >= '0' && s[i] <= '9'){
                cnt = cnt * 10 + s[i] - '0';
            }
            else if(s[i] == '['){
                s_num.push(cnt);
                s_str.push(cur);
                cnt = 0;
                cur = "";
            }
            else if(s[i] == ']'){
                int k = s_num.top();s_num.pop();
                string temp;
                while(k){
                    temp += cur;
                    --k;
                }
                cur = s_str.top() + temp;
                s_str.pop();
            }
            else{
                cur += s[i];
            }
        }
        return cur;
    }
};
```