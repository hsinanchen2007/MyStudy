### 解题思路
其实就是利用数学公式来快速推测出最多能循环多少次，并求出剩余的糖果数量
然后将使用遍历每一项，将多余糖果数量依次分配，最终求结果

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int c, int n)
    {
        int t = 0; // 当前循环次数
        while (true) { // 不断循环知道找到解跳出
            /**
             * 利用数学公式，每一次循环：
             * t: 循环次数 n 人数 tn: 本次循环 tn1: 下一次循环 c: 糖果总数
             * (tn * (tn + 1)) / 2 < c && (tn1 * (tn1 + 1)) / 2 >= c
             */
            int tn = t * n;
            int tn1 = (t + 1) * n;
            if (tn * tn + tn < 2 * c
                && tn1 * tn1 + tn1 >= 2 * c) {
                // 此时 t 就是最多循环次数(如果刚好分完，则少1次)
                break;
            }
            t++;
        }
        
        int tn = t * n;
        int out = c - (tn * tn + tn) / 2; // 剩余糖果
        
        vector<int>result(n);
        for (int i=0; i<n; i++) {
            result[i] = (i + 1) * t + tn * (t - 1) / 2; // t 循环完成 每个人糖果
            
            // 最后依次手动发放
            if (out >= tn + i + 1) {
                result[i] += (tn + i + 1);
                out -= (tn + i + 1);
            } else {
                result[i] += out;
                out = 0;
            }
        }
        return result;
    }
};
```