### 解题思路
实在是不想手打按键和字母的对应数组了；

### 代码

```cpp
class Solution {
private:
    vector<string> ans;
    int n ;
public:
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        if(n == 0) return {};
        char* dig = new char[strlen(digits.c_str())+1];
        strcpy(dig, digits.c_str());
        string s;
        dfs(dig,s,0);
        return ans;
    }
    void dfs(char* dig,string s,int k){
        if(k == n) {
            ans.push_back(s);
            return;
        }
        if(dig[k] < '7'){
            for(int i = 0;i<3;i++){
                dfs(dig,s+char(int('a') + int((dig[k]-'2')*3+i)),k+1);
            }
        }
        if(dig[k] == '7'){
            for(int i = 0;i<4;i++){
                dfs(dig,s+char(int('a') + int((dig[k]-'2')*3+i)),k+1);
            }
        }
        if(dig[k] == '8'){
            for(int i = 0;i<3;i++){
                dfs(dig,s+char(int('a') + int((dig[k]-'2')*3+i+1)),k+1);
            }
        }
        if(dig[k] == '9'){
            for(int i = 0;i<4;i++){
                dfs(dig,s+char(int('a') + int((dig[k]-'2')*3+i+1)),k+1);
            }
        }
    }
};
```