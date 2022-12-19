### 解题思路
方法一：暴力递归。时间复杂度为O（n²），空间复杂度O（n），输入用例'45'时不通过。
方法二：动态规划。时间复杂度O（n），空间复杂度O（n）。将每一级的结果存入数组中。

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int[] arr = new int[n];
        arr[1] = 1;
        arr[2] = 2;

        for(int i=3;i<n;i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n-1]+arr[n-2];
    }
}
```