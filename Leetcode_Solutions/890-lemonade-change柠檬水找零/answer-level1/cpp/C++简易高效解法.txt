# 题目用到贪心算法思想的是，当收到20元的时候， 优先使用十元找零，再使用五元找零。

# 情景解析
情况一：收到5元，直接收钱。
情况二：收到10元，有5元找零,直接收钱。
情况三：收到10元，无5元找零，返回false。
情况四：收到20元，有10元和5元找零，直接收钱。
情况五：收到20元，无10元但是有3张5元，直接收钱。
其他二十元情况，返回false;

# 代码如下：
```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num5 = 0, num10 = 0;
        for (int b : bills) {
            if (b == 5) {
                ++num5;
            }
            else if (b == 10) {
                if (num5 > 0) {
                    --num5;
                    ++num10;
                }
                else{
                    return false;
                }
            }
            else {
                if (num10 > 0 && num5 > 0) {
                    --num10;
                    --num5;
                }
                else if (num5 > 2) {
                    num5 -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
```
