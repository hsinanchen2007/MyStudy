### 解题思路
1.若能被2，3，5整除，则不断的除去2，3，5。
2.若最后迭代的商不是1，说明还有其他质因子，因此返回false，说明不是丑数。
3.若最后迭代的商是1，说明没有其他质因子，因此返回true，说明是丑数。

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if(num == 0){
            return false;
        }
        
        while(num != 1){
            if(num % 2 == 0){
                num /= 2;
                continue;
            }
            
            if(num % 3 == 0){
                num /= 3;
                continue;
            }
            
            if(num % 5 == 0){
                num /= 5;
                continue;
            }
            return false;
        }
        return true;
    }
};
```