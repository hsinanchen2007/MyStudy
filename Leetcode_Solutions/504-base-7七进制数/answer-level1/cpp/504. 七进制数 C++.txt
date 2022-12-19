### 解题思路
1.判断是否是负数，若是负数则转换成正数在做处理并在最后字符串上加上负号。
2.先去mod7，结果转换成char行压入字符串首处，并除以7做迭代处理。

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        else{
            string str = "";
            bool neg = false;
            if(num < 0){
                neg = true;
                num = -num;
            }
            
            while(num){
                str.insert(0, 1, (char)(num % 7 + 48));
                num = num / 7;
            }
            
            if(neg){
                str.insert(0, 1, '-');
            }
            return str;
        }
    }
};
```