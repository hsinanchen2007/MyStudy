### 解题思路
从左到右扫一遍 如果当前字母与上一个字母不一样则更新计数器

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string now;
        now.push_back(S[0]);
        string ans;
        int count=1;
        for(int i=1;i<=S.length();++i){
            if(S[i]==now[0]){
                count++;
            }
            else{
                ans+=now;
                ans+=(to_string(count));
                now=S[i];
                count=1;
            }
        }
        if(ans.length()<S.length())
            return ans;
        else
            return S;
    }
};
```