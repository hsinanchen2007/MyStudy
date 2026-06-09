### 解题思路
遍历字符串，挨个排查所有条件
### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int res = 0,flag = 0,max = 0,start = 0;

        for(int i=0;i<str.size();i++){
            if(str[i] == ' ')
                if(start == 0)
                    continue;
                else
                    break;
            if(!(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')))
                break;
            if(str[i] == '-'){
                if(start == 1)
                    break;
                start = 1;
                if(flag == 1)
                    return 0;
                flag = -1;
            }
            if(str[i] ==  '+'){
                if(start == 1)
                    break;
                start = 1;
                if(flag == -1)
                    return 0;
                flag = 1;
            }
            if(str[i] >= '0' && str[i] <= '9'){
                start = 1;
                if(res < (INT_MAX - (str[i]-'0'))/10){
                    res = res*10 + str[i] - '0';
                }
                else{
                    if((str[i] - '0' >= 8 && flag == -1)||(flag == -1 && res > INT_MAX/10))
                        return INT_MIN;
                    if((str[i] - '0' >= 7 && flag != -1)||(flag != -1 && res > INT_MAX/10))
                        return INT_MAX;
                    else
                        res = res*10 + (str[i] - '0');
                    break;
                }
            }
        }

        if(flag == -1){
            res = -res;
        }

        return res;
    }
};
```