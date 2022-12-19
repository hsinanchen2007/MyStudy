### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int len=s.length();
        char z[1000]={0};
        int add=2*numRows-2;
        int k=0;
        int j=0;
        for(int i=0;i<numRows;i++){
            for(j=i;j<len;j+=add){
                z[k]=s[j]; 
                if(i==0||i==numRows-1||j+add>=len) k++;
                else k+=2;
            }
            if(j-add+2*numRows-2*(i+1)<len) k++;
        }
        k=0;
        for(int i=add-1;i>=numRows;i--){
            while(z[k]!=0){
                k++;
            }
            for(int j=i;j<len;j+=add){
                z[k]=s[j];
                k=k+2;
            }
        }
        return z;
    }
};
```