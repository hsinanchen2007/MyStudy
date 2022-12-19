### 解题思路
从最后一个元素往前遍历，找第一个不为9的元素。
如果找到，则将这个元素+1，同时后面所有的元素全部置0。
如果没找到，说明是[9,9…………9]型数组，则将数组全部置0，并在头部插入1。

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]!=9)
            {
                for(int j=digits.size()-1;j>i;j--)
                    digits[j] = 0;
                digits[i]++;
                return digits;
            }
        }
        for(int i=digits.size()-1;i>=0;i--)
            digits[i] = 0;
        digits.insert(digits.begin(),1);
        return digits;      
    }
};
```