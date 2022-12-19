### 解题思路
暴力法，普通数学加法思路，按位相加，进位为 t 

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int a_length=a.length()-1;
        int b_length=b.length()-1;
        string result;
        int t=0;
        while(a_length>=0||b_length>=0||t!=0){            
            if(a_length>=0){
                t=t+(a[a_length]-'0');
                a_length--;
            }
            if(b_length>=0){
                t=t+(b[b_length]-'0');
                b_length--;
            }
            if(t==0){
                result.insert(0,"0");
            }               
            else if(t==1){
                result.insert(0,"1");
                t=0;
            }               
            else if(t==2){
                result.insert(0,"0");
                t=1;
            }
            else{
                result.insert(0,"1");
                t=1;
            }
        }
        return result;
    }
};
```

执行结果惊了
![image.png](https://pic.leetcode-cn.com/32f5d47f10375491f14fb6796d130ca2648572423a4ff0234ec91b18aa5f636c-image.png)
