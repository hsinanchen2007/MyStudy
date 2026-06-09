### 解题思路
此处撰写解题思路
1. 小于0的数都是false；
2. 其他数只要逆置然后与原来的数比较是否相等；
3. 用`x!=0&&max/10<sum`来判断是否溢出。

### 代码

```cpp
class Solution {
public:
#include <climits>
    bool isPalindrome(int x) {
        int pop,count;
        int sum=0;
        bool legal = true;
        int max = INT_MAX;
        int tmp = x;
        if(x<0){
            return false;
        }
        if(x==0){
            return true;
        }
        while(x!=0){
            pop = x%10;
            x=x/10;
            sum = sum*10+pop;
            if(x!=0&&max/10<sum){
                return false;
            }
        }
        if(sum!=tmp){
            return false;
        }
        else{
            return true;
        }
    }
};
```