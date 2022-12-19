### 解题思路
一开始想用除留余数法排除没有2,3,5因数的数，后来觉得太麻烦。
首先排除非正整数的输入，以及1这个固定的特殊情况。
接下来对num进行判断，分别判断是否能被2,3,5整除，若能，进行/=操作，若不能，返回错误。
直至num等于1退出循环，返回正确。

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if(num<=0){
            return false;
        }
        else{
            if(num<=2){
                return true;
            }
            else{
                while(num!=1){
                    if(num%2==0){
                        num/=2;
                    }
                    else if(num%3==0){
                        num/=3;
                    }
                    else if(num%5==0){
                        num/=5;
                    }
                    else{
                        return false;
                    }
                }
                return true;
            }
        }
    }
};
```