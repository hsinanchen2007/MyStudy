### 解题思路
把s2乘以2，比如s1=“waterbottle”，s2=“erbottlewat”，s2*2=“erbottlewaterbottlewat”，若s2是s1旋转而成，s1一定会在s2*2中，只需对字符串进行一些比较即可。

### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        if(m!=n) return false;
        int i=0,j=0,x=0;
        while(i<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
                x++;
            }else{
                i=0;
                j++;
                x++;
            }
            j>=m?j%=m:j;
            if(x>=m*2) break;
        }
        if(i==m) return true;
        else return false;
    }
};
```