### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/aef63054b9a66c479c8f511f7dbb269feedb226fcc96968cdfb52d1033bbd380-image.png)

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        while(str[index]==' ')
            index++;
        int flag = 1;
        if(str[index]=='-'){
            flag = -1;
            index++;
        }
        else if(str[index]=='+')
            index++;
        else if(isalpha(str[index]))
            return 0;
        int ans = 0;
        while(isdigit(str[index])){
            int temp = str[index++]-'0';
            if(flag==1){
                if(ans>INT_MAX/10 || (ans == INT_MAX/10 && temp>7))
                    return INT_MAX;
            }
            else{
                if(ans>INT_MAX/10 || (ans == INT_MAX/10 && temp >=8))
                    return INT_MIN;
            }
            ans = ans*10 + temp;
        }
        return ans*flag;
    }
};
```