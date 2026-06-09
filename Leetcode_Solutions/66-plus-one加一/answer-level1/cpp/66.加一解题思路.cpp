### 解题思路
解题思路就是从最后一位往前不断进位，当进位至数组第一位时，在数组头前插入1.
例如 999 -> 000 数组头加1 000->1000。
顺便请教一个问题 else中是直接return呢好呢 还是就下面的写法 先break出来 代码最后只写一个return？ 
### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--)//从数组最后往前看
        {
            if(digits[i]+1 > 9)//若最后一位是9 给它加1变成0 然后继续循环给前一位加1，若前一位加1还是大于9那么就继续给前一位加1.....
                digits[i] = 0;
            else // 若前一位加1小于等于9，那么这一位用加1后来赋值，可以跳出这个进位循环
            {   
                digits[i] = digits[i] + 1;
                break; 
            }
        }
        if(digits[0] == 0)//如果每一位都往前进1，直到第一位。就会导致数组都为0，此时需要在数组的头加一位
            digits.insert(digits.begin(),1);
        return digits;
    }
};
```