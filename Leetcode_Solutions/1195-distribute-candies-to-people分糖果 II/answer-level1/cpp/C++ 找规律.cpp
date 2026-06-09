### 解题思路
算规律，找出关系式
假设m为第几次分，从1开始计算，如果全部人都可以分满，那么总共要分 m - 1) * n * n + (1+n)*n 的糖果。
这里可以计算一下，总共可以分几次。最后一次可能是分不满的。
然后第i个人m-1次都分满的时候，得到的糖果总数目为 i*(m-1)+n*(m-1)*(m-1-1)/2。 第m次如果分满的情况，它该次得到的糖果数目是i + (m-1) * n。
这里可以处理一下剩余最后一次分的糖果应该怎么分。

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        int m = 1;
        while ((m - 1) * n * n + (1+n)*n / 2 < candies) {
            candies -= (m - 1) * n * n + (1+n)*n / 2;
            m++;
        }
        vector<int> res;
        for (int i = 1; i<=num_people; i++) {
            int t = i + (m-1) * n;
            if (candies > t) { // candies 是第m次分的时候，还剩多少
                res.emplace_back(i*(m-1)+n*(m-1)*(m-1-1)/2 + t);
            } else {
                res.emplace_back(i*(m-1)+n*(m-1)*(m-1-1)/2 + max(0, candies));
            }
            candies -= t;
        }
        return res;
    }
};
```