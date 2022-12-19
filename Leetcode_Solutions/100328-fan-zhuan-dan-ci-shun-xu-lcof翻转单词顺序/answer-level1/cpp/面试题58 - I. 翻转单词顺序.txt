### 解题思路
主体：
    word+=(' '+ans);
    ans = word;
注意：
    用s.at[i]一旦为空，会出现越界错误，这里用是s[i]访问则不会有这个问题
    最后需要处理ans最后一个空格，故例子" "，要加以 flag 判断是否进入主体，否则处理最后一个空格会出现越界错误
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string word;
        bool flag = false;
        int i=0;
        while(s[i]!='\0'){
            if(s[i] != ' ' && s[i]!='\0'){
                flag = true;
                   while(s[i]!=' ' && s[i]!='\0'){
                       word+=s[i++];
                   }
                   word+=(' '+ans);
                   ans = word;
                   word.clear();
            }
            else
                i++;
        }
        if(flag)
            ans.erase(ans.size()-1,1);
        ans+='\0';
        return ans;
    }
};

```