![image.png](https://pic.leetcode-cn.com/d3502b562ec9001e20275462cbce5ae2f392d87a3ecc104c101976efdada7f33-image.png)

### 解题思路
利用栈的pair形式保存字符串的重读次数num和字符串c
遍历s
1、若判断为数字，则更新num，
2、若为'[',入栈(num,"");
3、若为']',将当前栈顶元素的c重复num被保存在tmp中，然后弹出栈顶元素，判断栈是否为空，若为空，则将tmp追加到res后；若为非空，则将tmp加到栈顶pair的second后
4、否则为字符：若当前栈为空，则将字符串添加到res后，否则添加到栈顶的pair的second后。
返回res；
### 代码

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int,string>> st;
        string res;
        int num=0;
        for(auto c:s){
            if (isdigit(c)){
                num = num * 10 + c - '0';
                continue;
            }
            if(c=='['){
                st.push(make_pair(num,""));
                num=0;
                continue;
            }
            if(c==']'){
                int cnt=st.top().first;
                string tmp="";
                while(cnt){
                    tmp+=st.top().second;
                    cnt--;
                }
                st.pop();
                if(st.empty()) res+= tmp;
                else st.top().second+=tmp;
                continue;
            }
            if(!st.empty())st.top().second+=c;
            else res+=c;
        }
        return res;
    }
};
```