### [1342. 将数字变成 0 的操作次数](https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-to-zero/)

#### 题解
+ 统计num二进制位数和二进制位上1的个数，答案为其和-1，因为所有除1外所有单数会要减1和右移1位，而1⃣️只要进行两者操作中的一个。
+ 特判num为0
+ 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)
    
#### 代码
```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while(num)
        {
            if(num & 1 != 0) res ++;
            res ++;
            num >>= 1;
        }
        return max(0, res-1);
    }
};
```