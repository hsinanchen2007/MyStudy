### 解题思路
1.不同的字符必须为2个或0个
2.字符串相同时，字符串中必须存在重复字符

### 代码

```cpp

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size())return false;
        if(A==B){
            for(int i=0;i<A.size();i++){
                if(count(A.begin(),A.end(),A[i])>=2)return true;
            }
            return false;
        }
        int diff_char_num=0;
        char c[4];
        for(int i=0;i<A.size();i++){
            if(A[i]!=B[i]) {
                diff_char_num++;
                if(diff_char_num>2)return false;
                c[diff_char_num*2-2]=A[i];
                c[diff_char_num*2-1]=B[i];
                
            }

        }
        if(diff_char_num!=2)return false;//必须存在
        if(c[0]==c[3]&&c[2]==c[1])return true;
        else return false;

    }
};
```