```
/**
    1、target 有值
    2、有波峰 有波谷 （波峰值最大 波谷值最小） 或者 只升序
 */
public class Solution {
    public int Search(int[] nums, int target) {
        int length = nums.Length;
        int nullAns = -1;
        if (length == 0) {
            return nullAns;
        } else if (length == 1 && nums[0] == target) {
            return 0;
        }
        int index = 0;
        bool hasSame = false;
        // 是否有 target 值
        while (index < length) {
            if (nums[index] == target) {
                hasSame = true;
                break;
            }
            index++;
        }
        if (!hasSame) {
            return nullAns;
        }
        int min = int.MaxValue, max = int.MinValue;
        int k = 1, m = -1;
        bool first = false;
        while (k < length) {
            if (nums[k - 1] > nums[k]) {
                // 是否只有一个波峰、波谷
                if (first) {
                    return nullAns;
                }
                min = nums[k];
                max = nums[k - 1];
                m = k - 1;
                first = true;
            } else {
                // 升序时所有值 均大于最小值，小于最大值
                if (m > 0) {
                    if (nums[k] < min || nums[k] > max) {
                        return nullAns;
                    }
                }
            }
            k++;
        }

        return index;
    }
}
// Accepted
//     196/196 cases passed (108 ms)
//     Your runtime beats 92.31 % of csharp submissions
//     Your memory usage beats 12 % of csharp submissions (23.8 MB)
```
