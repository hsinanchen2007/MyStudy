### 解题思路
总体思路，最慢吃香蕉的速度是1个，因为保安回来的时间可能很长，珂珂希望尽量慢慢吃；
那最快呢？因为一次最多也只能吃1堆，所以最快速度就是每小时能吃掉最大的那一堆
找到两边的边界后就可以开始找合适的速度，穷举可能超时，那就用二分法，以整个区间的中点速度开始尝试，
发现吃快了就尝试左区间，吃慢了就尝试右区间

### 代码

```cpp
/*总体思路，最慢吃香蕉的速度是1个，因为保安回来的时间可能很长，珂珂希望尽量慢慢吃；
那最快呢？因为一次最多也只能吃1堆，所以最快速度就是每小时能吃掉最大的那一堆
找到两边的边界后就可以开始找合适的速度，穷举可能超时，那就用二分法，以整个区间的中点速度开始尝试，
发现吃快了就尝试左区间，吃慢了就尝试右区间*/
class Solution {
public:
    /*计算以这个速度多久能吃完*/
    int Try2Eating(vector<int>& piles, int s)
    {
        int sum = 0;
        for (auto n : piles) {
            int base = n / s;//整除，几个小时能正好吃完或“剩一点”
            int remains = n % s;
            if (remains != 0) {//还“剩一点”
                sum += (base + 1);
            } else {//正好吃完
                sum += base;
            }
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int H)
    {
        sort(piles.begin(), piles.end());
        int left = 1;//最小速度
        int right = piles.back();//最大速度
        int mid = 0;
        int minSpeed = right;
        while (left <= right) {
            mid = (right + left) / 2;//折半
            int curH = Try2Eating(piles, mid);
            if (curH <= H) {
                if (mid < minSpeed) {
                    minSpeed = mid;//保存当前最小速度
                }
                right = mid - 1;//在保安回来前能吃完，试试看能不能再慢一点
            } else {
                left = mid + 1;//吃的太快了，需要减速，不保存结果
            }
        }

        return minSpeed;
    }
};
```