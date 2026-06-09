### 解题思路
利用flag存储+-，利用start确定是否已经开始，若之后再出现不是数字则break；
复杂度O(n)吧，执行用时一会0，一会4ms

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        long long result(0);
        int str_size=str.size();
        int flag=1;//存储+-标志位
        bool start=false;//数字读取是否已经开始
        //若之后再出现不是数字的字符，则break
        for(int i=0;i<str_size;i++){
            if(str[i]==' '&&start==false){
                continue;
            }
            if(str[i]=='-'&&start==false){
                flag=-1;
                start=true;
                continue;
            }
            if(str[i]=='+'&&start==false){
                flag=1;
                start=true;
                continue;
            }
            if(str[i]>='0'&&str[i]<='9'){
                start=true;
                result=result*10+str[i]-48;
                //判断溢出
                if(flag*result>INT_MAX)
                    return INT_MAX;
                if(flag*result<INT_MIN)
                    return INT_MIN;
                continue;
            }
            else{
                break;
            }
        }
        return flag*result;
    }     
};
```