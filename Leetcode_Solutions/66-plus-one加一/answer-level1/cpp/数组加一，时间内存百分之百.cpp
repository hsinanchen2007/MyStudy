### 解题思路
代码从向量的尾部开始遍历，逐位加一，若加一后小于10，直接跳出，否则将该位减10继续下一个循环，若第0位加一后大于等于10，则还要在向量的头部插入1。在写代码时for循环中的等号一定要加，否则会漏掉第0位，判断第0位是否大于等于10的等号也一定要加，否则会漏掉等于10的情况。

### 代码

```cpp
#include <math.h>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=digits.size();
        for(int i=size-1;i>=0;i--){
            digits[i]=digits[i]+1;
            if(digits[i]<10){
                break;
            }
            else{
                digits[i]=digits[i]-10;
                if(i==0){
                    digits.insert(digits.begin(),1);
                }
            }
        }
            
        return digits;
    }
};
```