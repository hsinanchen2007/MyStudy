### 解题思路
原谅我看不懂各种大神的位运算，这里就发一个不需要位运算的。
思想就是类似快排中 partition 的分组。
从末位开始向前，每次根据当前位是0还是1来分组，数组内交换，不占额外空间。
重点是，这样分组一定能保证相同的数分到同一组中。

然后看两个组的size，根据下标直接计算得到。
因为只有一个数字出现了1次，所以肯定有一组size被3整除，说明 single 在另一组中。
那么递归调用，在另一组中如法炮制，注意 判断 bit 位也要+1。
递归终止条件就是只剩一个数。

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return find(nums, 0, nums.size()-1, 0);
    }

    int find(vector<int>& nums, int s, int e, int bit) {
        if (s == e) return nums[s];
        int l = s-1;
        for (int i = s; i <= e; ++i) {
            if (test(nums[i], bit) == 0) {
                swap(nums[l+1], nums[i]);
                l++;
            }
        }
        int left = l - s + 1;
        int right = e - l;
        if (left % 3 == 0) {
            return find(nums, l+1, e, bit+1);
        } else {
            return find(nums, s, l, bit+1);
        }
        return 0;
    }

    int test(int n, int bit) {
        return (n >> bit) & 1;
    }
};
```