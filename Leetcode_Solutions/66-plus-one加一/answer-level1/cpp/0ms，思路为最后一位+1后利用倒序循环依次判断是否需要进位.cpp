### 解题思路
首先在原数组的第一位上插入0，用于在连续满足进位条件时进位使用

接下来对数组最后一位元素+1；

后对整个数组从后往前遍历判断当前元素是否等于10，若等于10则当前元素置0，前一个元素+1；遍历n-1到1的元素，最后将数组进行输出

由于引起整个进位循环的操作只有一个，即最后一位元素满足了进位条件，此时才会对前一位元素进行判断是否满足进位，引发进位连锁；

故当不满足进位条件时，直接跳出循环，输出除之前添加的第一个0元素外的数组即可

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.insert(digits.begin(), 0);        //首先在数组最前插入一个0，用于判断进位
        int n = digits.size();
        digits[n - 1] += 1;                     //最后一位+1
        for(int i = n - 1; i > 0; i--){         //从后往前遍历一遍数组，判断是否需要进位
            if(digits[i] == 10){
                digits[i] = 0;
                digits[i - 1] += 1;             //进位
            }
            else return vector<int>(digits.begin() + 1, digits.end());;                         //若没有进位，则直接跳出循环输出，因为只可能由最后一个元素进位引起前面的元素再进位
        }
        return digits;
    }
};
```