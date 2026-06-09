### 解题思路
参考用户[@owenzzz](/u/owenzzz/)的方法的实现

1. 先对stones数组进行排序

2. 求最大值的方法为：
    a) `stones[n-1] - stones[0] - n + 1`为**未被占用**的位置的个数，设为`m1`。但是当你移动`stones[0]`时，`stones[0]`不能放在`stones[0]`和`stones[1]`之间，因为那样`stones[0]`还是放在也端点，因此会产生`stones[1] - stones[0] - 1`个空位不可以移动。同理，假如一开始移动的是`stones[n-1]`，会产生`stone[n-1] - stones[n-2] - 1`个不可以放置的位置。设不可放置的位置数为`m2`。那么实际上最多有`m1 - m2`个位置是可以放置的。
    b) 我们可以把将`stones[0]`(首部端点)石子放在非端点的空位，也可以将`stones[n-1]`(尾部端点)石子放在非端点的空位，完成一次放置。要求最大值，我们希望这个窗口收缩的足够慢。事实上，我们可以让未占用的位置的个数每次都仅减1，这样`m`个可放置的位置可以最多经过`m`次移动

3. 求最小值的方法：
    a) 因为这个游戏结束时，一定会产生长度为`n`的连续排列的石子。因此，一开始我们只要找到一个长度**不大于**`n`的窗口，使该窗口里面的石子数目最多。这样移动的次数会最少。
    b) 有一种特例：如`[100,101,102,103,107]`，石子个数为`n` (5个)。窗口大小为`n-1`(4)时且前`n-1`个石子连续排列时。不能直接把`107`移动到`104`的位置，而是需要把`100`移动到`106`，然后把`107`移动到`105`，这样就需要`2`次移动。

### 代码

```cpp
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        //剩余的空间
        int left_over = stones[n-1] - stones[0] - n + 1;
        // 使得能放的空间最大
        int m = min(stones[1]-stones[0]-1, stones[n-1]-stones[n-2]-1);
        int max_cost = left_over - m;
        int min_cost = max_cost;

        //滑动窗口，使的窗口内的石子最多，那么填充时所需石子移动的步数就最少
        int left = 0, right = 0;
        for(;left<n;++left){
            while(right+1 < n && stones[right+1] - stones[left] + 1 <= n){
                // 使的窗口不超过n的最大的right
                ++right;
            }
            int cost = n - (right - left + 1);
            //如果一排有连续的n-1个石子，而且他们连续排列
            if(right - left + 1 == n-1 && stones[right] - stones[left] + 1 == n-1){
                cost = 2;
            }
            min_cost = min(min_cost, cost);
        }
        return {min_cost, max_cost};
    }
};


```