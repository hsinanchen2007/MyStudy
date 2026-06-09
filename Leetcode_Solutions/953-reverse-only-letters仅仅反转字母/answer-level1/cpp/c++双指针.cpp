
### 代码

```cpp
class Solution {
public:
    bool isalp(char m)
    {
        if((m>='a'&&m<='z')||(m>='A'&&m<='Z'))
            return true;
        return false;
    }
    string reverseOnlyLetters(string S) {
        int i=0;
        int j=S.size()-1;
        while(i<j)
        {
            if(isalp(S[i])&&isalp(S[j]))
            {
                char m=S[i];
                S[i]=S[j];
                S[j]=m;
                i++;
                j--;
            }
            else if(isalp(S[i])&&!isalp(S[j]))
                j--;
            else if(!isalp(S[i])&&isalp(S[j]))
                i++;
            else{
                i++;
                j--;
            }
        }
        return S;
    }
};
```