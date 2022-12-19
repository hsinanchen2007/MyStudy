思路就是算出两个数组，一个代表从左开始的最大前缀和，一个代表从右开始的最大前缀和。
之后遍历所有的负数，即：求出删除该负数时的结果
假设删除的负数的坐标为i，那么左边的最大前缀和为recordLeft[i-1]，右边的最大前缀和为recordRight[i+1]，
只有值大于0的时候才选择。
需要注意的是，如果两者都不选择的话，会违反题目要求，这里就直接默认选择当前的值。
```
/**
 * Solution
 *
 * @author jianghe
 * @since 2020-03-16
 */
class Solution {
    public int maximumSum(int[] arr) {
        // 左起最大前缀和
        int[] recordLeft = new int[arr.length];
        // 右起最大前缀和
        int[] recordRight = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            if (i == 0) {
                recordLeft[i] = arr[0];
                continue;
            }
            recordLeft[i] = Math.max(arr[i], recordLeft[i - 1] + arr[i]);
        }
        for (int i = arr.length - 1; i >= 0; i--) {
            if (i == arr.length - 1) {
                recordRight[i] = arr[arr.length - 1];
                continue;
            }
            recordRight[i] = Math.max(arr[i], recordRight[i + 1] + arr[i]);
        }

        int res = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] >= 0) {
                continue;
            }
            int temp = 0;
            if (i - 1 >= 0 && recordLeft[i - 1] >= 0) {
                temp += recordLeft[i - 1];
            }
            if (i + 1 < arr.length && recordRight[i + 1] >= 0) {
                temp += recordRight[i + 1];
            }
            if ((i - 1 < 0 || recordLeft[i - 1] < 0)
                && (i + 1 >= arr.length || recordRight[i + 1] < 0)) {
                temp = arr[i];
            }
            if (res < temp) {
                res = temp;
            }
        }
        return res;
    }
}
```
