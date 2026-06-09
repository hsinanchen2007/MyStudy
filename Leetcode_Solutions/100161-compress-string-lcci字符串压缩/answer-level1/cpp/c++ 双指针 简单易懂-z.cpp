### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int i=0,j=0,len=S.size();
        string res;

        while(i < len)         //i用来定位该字母的初始位置，j用来移动
        {
            while(S[i] == S[j])   
                j++;
            res += S[i] + to_string(j - i);         
            i=j;
        }
        if(res.size() >= len)  return S;
        return res;
    }
};
```