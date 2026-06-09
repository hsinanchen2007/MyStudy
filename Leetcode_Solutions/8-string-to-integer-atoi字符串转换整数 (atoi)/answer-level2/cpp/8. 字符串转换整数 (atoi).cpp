### 解题思路
执行用时 :
0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
6.2 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int first=0;
        int res=0;
        int neg=1;
        int bit=0;
        for(int i=0;i<str.length();i++){
            if(first==0){
                if(str[i]==' '){
                    continue;
                }else if(str[i]=='+'){
                    neg=1;
                }else if(str[i]=='-'){
                    neg=-1;
                }else if(str[i]<='9'&&str[i]>='0'){
                    res=str[i]-'0';
                    bit=1;
                }else{
                    return 0;
                }
                first=1;
            }else{
                if(str[i]<='9'&&str[i]>='0'){ 
                    int tmp=str[i]-'0';
                    if(bit>=9){
                        if(res>(INT_MAX-tmp)/10){
                            return (neg==-1)?INT_MIN:INT_MAX;
                        }
                    }
                    res=res*10+tmp;
                    bit++;
                }else{
                    return res*neg;
                }
            }
        }
        return res*neg;
    }
};
```