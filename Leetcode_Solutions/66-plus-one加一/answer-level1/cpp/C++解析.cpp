思路：
这个题目看到的第一反应就是直接数组从后往前遍历，进行加一操作，如果不需要进位可以直接加一退出即可，如果需要进位则继续进行操作。
**PS：考虑到数组可能会出现99999....这种全是9的情况，它的加一会导致整个数组变长1位，并且首位是1，其余全是0.**
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int nineCount = 0; //变量标记当前数组包含9的个数
        for(int i = digits.size()-1;i>=0;i--)//从数组尾部遍历
        {
            if(digits[i] <9) {    //如果当前的数字小于9，那么加一操作无需进位，直接加一跳出循环
                digits[i] += 1;
                break;
            } else {            //如果当前的数字等于9了，需要继续进行判断，同时把该位置0。计数器同时也要加一
                digits[i] = 0;
                nineCount ++;
            }
        }

        if (nineCount == digits.size()) { //这种情况说明当前的数组全是999.....需要首位置1，末尾添0
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
```



第一次写题解，有不完善的地方还请多包含