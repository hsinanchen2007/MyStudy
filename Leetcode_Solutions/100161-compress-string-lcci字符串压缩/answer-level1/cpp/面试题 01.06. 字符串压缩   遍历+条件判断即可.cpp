### 解题思路
to_string(count)  数字转字符串
if(res.size()>=S.size()) return S; 注意有等号

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int count=1;
        string res="";
        for(int i=0;i<S.size();i++){
            if(S[i]==S[i+1]){
                count++;

            }
            else{
                res+=S[i]+to_string(count);
                count=1;
            }
        }
        if(res.size()>=S.size()) return S;
        else return res;
    }
};
```