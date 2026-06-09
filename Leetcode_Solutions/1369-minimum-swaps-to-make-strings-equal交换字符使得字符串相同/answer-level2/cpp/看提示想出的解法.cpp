### 代码

```cpp
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size(),k=0,xn=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x')xn++;
                k++;
            }
        }
        if(k&1)return -1;
        if(xn & 1)return xn/2 + (k-xn)/2 + 2;
        else return k / 2;
        
    }
};
```