
首先是二分的思路, 在这个高亮答案里添加了一点东西. 提高了二分的效率.

https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/

```{java}
class Solution {
    public int findDuplicate(int[] nums) {
        int len = nums.length;
        int L = 1;
        int R = len - 1;
        int mid = (L + R) >> 1;
        int ans = process(mid, nums);
        while (ans < 0) {
            if (ans == -1) {
                R = mid;
            } else {
                L = mid + 1;
            }
            mid = (L + R) >> 1;
            ans = process(mid, nums);
        }
        return ans;
    }

    public int process(int pivot, int[] nums) {
        // 计算小于基准数的个数
        int cnt1 = 0;
        // 计算等于的个数
        int cnt2 = 0;
        for (int i : nums) {
            if (i < pivot) {
                cnt1++;
            } else if (i == pivot) {
                cnt2++;
            }
        }

        // 找到了这个数
        if (cnt2 > 1) {
            return pivot;
        }
        // 判断是左边还是右边
        if (cnt1 + cnt2 > pivot) {
            return -1;
        } else {
            return -2;
        }
    }

}```
