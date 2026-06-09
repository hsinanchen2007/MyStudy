### 解题思路
搞清楚判断的先后顺序

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        long res = 0;
        bool flag = false;
        while(str[i] == ' '){
            i++;
        }

        if(str[i] == '+'){
            flag = false;
            i++;
        }else if(str[i] == '-'){
            flag = true;
            i++;
        }
        if(str[i] <'0' || str[i] > '9'){
            return 0;
        }

        if(flag){
            res = findNum(str,i);
            return max(-res,long(INT_MIN));
        }else{
            res = findNum(str,i);
            return min(res,long(INT_MAX));
        }

       
    }

    long findNum(string &str,int i){
        long res = 0;
         while(i<str.size()){
            if(str[i] <'0' || str[i] > '9'){
                i++;
                break;
            }
            res = res * 10 + str[i] - '0';
            if(res > INT_MAX){
                return res;
            }
            i++;
        }
        return res;
    }

};
```