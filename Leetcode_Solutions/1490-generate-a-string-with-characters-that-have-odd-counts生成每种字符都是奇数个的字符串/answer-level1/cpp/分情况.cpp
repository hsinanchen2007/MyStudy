### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string generateTheString(int n) {
        string s;
        if(n%2==0){
            int a1,b1;
            if(n%4==0){
                a1=n/2-1;
                b1=n/2+1;
            }
            else{
                a1=n/2;
                b1=a1;
            }
            for(int i=0;i<a1;i++){
                s+='a';
            }
            for(int i=0;i<b1;i++){
                s+='b';
            }
        }
        else{
            for(int i=0;i<n;i++){
                s+='a';
            }
        }
        return s;
    }
};
```