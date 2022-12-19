### 解题思路
和#7一样，只需要判断翻转后和原来是否相同，对于int型超长的问题你改一个long不就可以了么
如果对于long的溢出还是不行的话那就只能改为字符串方法了

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 ){                  // if x is minus
            return false;
        }

        else{
            long int x_temp = x;
            long int temp = 0;
            int pop;

            while(x_temp != 0){
                pop = x_temp%10;
                x_temp = x_temp/10;
                temp = temp *10 + pop;
            }
            
        if (temp != x){
            return false;
        }

        }
        return true;
    }
};
```