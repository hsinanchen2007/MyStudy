### 解题思路
直接扫描过去吧，遇到'/'进行处理
执行用时 :
4 ms, 在所有 cpp 提交中击败了98.43%的用户
内存消耗 :
9.2 MB, 在所有 cpp 提交中击败了99.81%的用户

### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
       // int l = 1;

        string curr = "";

        for(int i=0; i<=path.length(); i++) {
            char c = path[i];
            if(c=='/' || c=='\0') {
                if(curr==".") {
                    curr = "";
                    //return;
                }
                else if(curr == "..") {

                    if(ans.length()>1 && ans[ans.length()-1]=='/')
                        ans.pop_back();

                    while(ans.length()>1 && ans[ans.length()-1]!='/')
                        ans.pop_back();

                }
                else{
                    ans += curr;
                    if(ans[ans.length()-1]!='/')
                        ans += c;


                }
                curr = "";
            }
            else  {
                curr += c;
            }
        }
        
        while(ans.length()>1 && ans[ans.length()-1]=='/') 
            ans.pop_back();

        return ans;
    }
};
```