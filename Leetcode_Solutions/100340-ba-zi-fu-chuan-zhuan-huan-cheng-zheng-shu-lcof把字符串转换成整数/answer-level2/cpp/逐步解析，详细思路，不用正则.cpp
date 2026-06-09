### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了100.00%的用户
**（1）去除前面的空格**
```
        while(str[0]==' '){
            str.erase(str.begin());
        }
```
**（2）判断去除空格之后的首字符是+/-/数字/其他**
```
        int sign = 1; //数字正负判断
        if(str[0]=='-'){
            sign = -1;
            str.erase(str.begin());
        }else if(str[0]=='+'){
            str.erase(str.begin());
        }else if(str[0]<'0'||str[0]>'9'){
            return 0;
        }
```
**（3）逐步求出数**
核心代码：
```
sum = sum*10 + (str[i] - '0');
```
注意，需要判断数是否超过计算机最大数：
```
            if(sum>INT_MAX/10||(sum==INT_MAX/10&&str[i]-'0'>INT_MAX%10)){
                if(sign==-1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
```
以下为全代码：

```
        int sum = 0;
        int i = 0;
        while(str[i]>='0'&&str[i]<='9'){
            if(sum>INT_MAX/10||(sum==INT_MAX/10&&str[i]-'0'>INT_MAX%10)){
                if(sign==-1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            sum = sum*10 + (str[i] - '0');
            i++;
        }
```



### 代码

```cpp
class Solution {
public:
    int strToInt(string str) {
        while(str[0]==' '){
            str.erase(str.begin());
        }

        int sign = 1; //数字正负判断
        if(str[0]=='-'){
            sign = -1;
            str.erase(str.begin());
        }else if(str[0]=='+'){
            str.erase(str.begin());
        }else if(str[0]<'0'||str[0]>'9'){
            return 0;
        }

        int sum = 0;
        int i = 0;
        while(str[i]>='0'&&str[i]<='9'){
            if(sum>INT_MAX/10||(sum==INT_MAX/10&&str[i]-'0'>INT_MAX%10)){
                if(sign==-1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            sum = sum*10 + (str[i] - '0');
            i++;
        }
        
        return sign*sum;
    }
};
```