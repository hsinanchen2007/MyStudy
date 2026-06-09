### 解题思路
此处撰写解题思路
自底向上dp解法
分解问题 
1, 每行的最小为 min(row),
2, 每俩行的上一行每个元素最小为: 
每行i第j个元素 += 下一行除了自己所在位置的元素最小值  arr[i][j] == arr[i][j] + findMin(arr[i+1], exceptI)

先计算每俩行最小 直到第0行

最后 返回 每行的最小为 min(row)
### 代码

```java
class Solution {
    public int minFallingPathSum(int[][] arr) {
        if (arr.length == 0 || arr[0].length == 0) return 0;
        if (arr.length == 1) return findMin(arr[0], arr[0].length); // 只有一行 直接返回min(row)
        for (int i = arr.length-2; i > -1; i--) {
            dpfn(arr, i);
        }
        return findMin(arr[0], arr[0].length);
    }
    // dp方程 每行i第j个元素 += 下一行除了自己所在位置的元素最小值
    public void dpfn(int[][] arr, int i) {
        for ( int j = 0; j < arr[0].length; j++){
            arr[i][j] = findMin(arr[i+1], j) + arr[i][j];
        }
    }
    
    public int findMin(int[] nums, int except) {
        int res = 1<<30;
        for (int i = 0; i < nums.length; i++) {
            if (i != except) {
                res = Math.min(res, nums[i]);
            }
        }
        return res;
    }
}
```