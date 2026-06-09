### 解题思路
没用到vector的特性，基本是纯C解决的

### 代码

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int i,j,si, diff, dgts;
        for(i=0,j=0,si=0;i<chars.size()&&si<chars.size(); ){
            if(j<chars.size() && chars[i]==chars[j])j++;
            else{
                chars[si++]=chars[i];
                if(j-i>1){
                    diff=j-i;
                    dgts=log10(diff)+1;
                    while(dgts && diff){
                        chars[si+dgts-1]='0'+diff%10;
                        diff/=10;
                        dgts--;
                    }
                    si+=log10(j-i)+1;

                }
                i=j;
            }
        }
        chars.resize(si);
        return si;
    }
};
```