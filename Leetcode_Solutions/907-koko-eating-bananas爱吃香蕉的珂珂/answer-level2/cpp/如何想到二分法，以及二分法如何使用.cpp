### 解题思路
此处撰写解题思路

### 代码

```cpp
// 思路：以官方第一个例子为例： 因为其实就是求3/k + 6/k + 7/k + 11/k  < H
// 那k未知的情况下，k肯定不会大于数组中最大值，因为完全没意义，大于了一次也只能吃数组中最大值那么多。
// k肯定是大于等于数组最小值的，这主要取决于H.
// 所以从数组给的这个范围内，取元素，想到二分法，二分法一般需要传入一个 target,来和 nums[i]比较大小。
// 问题1： 那target此时怎么写呢？
// 问题2: 那么k有没有可能会只在数组范围内，而不是数组中的元素呢？
//        有可能，而二分法只能找数组中的元素，那怎么办呢？
// 问题1解答：需转换 ，其实target就是H, 但是 nums[i]的值怎么跟H对应呢，
//           那就是 nums[0]/K + nums[1]/k +... <= H,则算找到 target，所以这里封装个函数
// 问题2解答: 1中已经解答了，当通过二分法找到最后一个 nums[i]能满足时， 
//           将nums[i]的值依次减少1，直到找到最小的那个K.
//           但是这个最后一个 nums[i] 比较麻烦，何必呢？？？

// 其实问题2出来后，就应该明白，这题求得时 vector中的最小值到最大值之间的某个值，而不必是 vector中某一位的元素，所以直到 vector中的min和max即可。
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // 先对 piles排序，获取最小值和最大值
        sort(piles.begin(), piles.end());
        int left = 1; // 这里不能取 piles[0], 因为H足够大时，left是可以很小的。
        int right = piles[piles.size() - 1];

        while (left <= right) { // 当 left = right+1时，会跳出循环。
            int mid = left + (right - left) / 2;
            // 利用mid和target:H比较， mid其实就是我们每次假设的K
            if(canEatAll(piles, H, mid) == true) { // mid能够满足题意，那就看看mid再减去1能行不。
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        // 最后可以检查 left 越界的情况，因为while循环退出的条件是 left = right + 1,当然此时right也在变化。
        if (left > piles[piles.size() - 1])
            return -1;
        return left;
    }

    bool canEatAll(vector<int>& piles, int H, int possK) { // 可能的K
        int sumTime = 0; // possK时，需要的总时间。
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] % possK != 0) { // 说明有余数，则需要在多加上一个小时。 求余数是%
                sumTime = sumTime + (piles[i]/possK + 1);
            } else { // 刚好整除，就需要 piles[i]/possK 个小时即可  4/15 = 0
                sumTime = sumTime + (piles[i]/possK);
            }
        }

        if(sumTime <= H) { // 说明possK的速度，需要耗时 sumTime，是小于给定时间H的，满足。
            return true;
        } else {
            return false;
        }
    }
};
```