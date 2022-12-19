我们从头开始遍历数组，有以下 2 种情况：
1. 当前位置元素为 `1` ，表示这个位置不可以放置。由于左侧需要隔一个位置，那么下一个可能放置的位置至少是 `i + 2`
    如： `1 0 (1) 0 0 0 1 0 1 0 (1) 0 1 0 0` ，注意我们并不知道 `i + 2` 位置是否可行，这需要下一轮中判断。
2. 当前位置是0，分别检查左右是否为空
    - 若 `i > 0` ，检查左边是否是 `1`。如果是 `1` ，为了保证左侧间隔一个位置，下一个可能放置的位置至少是 `i + 1`。
        如： `1 0 1 (0) 1 0 1 (0) 0 0 0 1` ，注意我们并不知道 `i + 1` 位置是否可行，这需要下一轮中判断。
    - 若 `i < vector.size - 1`，检查右边是否为 `1` .如果是 `1`，下一个可能放置的位置至少是 `i + 3`。 这是因为：`i + 1` 位置是 `1` ；`i + 2`位置左侧的是 `1` ，不满足左侧为 `0` ；`i + 3` 左侧未知，需要下一轮判断。
        如： `1 0 1 0 1 0 (0) 1 0 1 0 (0) 1 0 0 0 0` ,注意我们并不知道 `i + 3` 位置是否可行，这需要下一轮中判断。
    - 不满足上面情况，说明当前位置左右都为空，可以放置，但不需要将这里赋值为 `1` 。因为我们可以知道 `i + 1` 位置是 `0` 且不能放置，下一个可能的位置是 `i + 2`。这样我们可以保证即使不将 `0` 改为 `1` ，也不会影响后面的判断。
        如： `1 0 (0) 0 0 0 1 0 (0) 0 1 0 0 0 0 0 1`

代码如下：
```
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;//we must return if n == 0.if not, 1 0 1 0 1 will not true
        int i = 0;
        while(i < flowerbed.size())
        {
            if(flowerbed[i] == 1)//this plot is not empty, the next plot we can place is (i + 2) at least
            {
                i += 2;
            }
            else
            {
                if(i > 0 && flowerbed[i - 1] == 1)//the left plot is not empty, wo should consider (i + 1)
                {
                    i++;
                }
                else if(i < flowerbed.size() - 1 && flowerbed[i + 1] == 1)//the right plot is not empty,
                {                                       //the next plot we can place is (i + 3) at least
                    i += 3;
                }
                else//wo can place in this plot, the next plot we can place is (i + 2) at least
                {
                    i += 2;
                    n--;
                    if(n == 0) return true;//place n flowers
                }
            }
        }
        return false;
    }
};
```
需要注意的是要提前判断 `n` 是否为 `0` 。否则对于序列 `1 0 1 0 1`，由于没有位置可放，我们不会进入
`if(n == 0) return true;//place n flowers` 这段代码，最后将返回 `false` 。