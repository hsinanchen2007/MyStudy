![srot.png](https://pic.leetcode-cn.com/f1c95cc7722a196ccfc2586d142a82aa3f4b05f6495f33fa08d79c70ad3d59d8-srot.png)
**这不就是升序之后，每两组的第一位值相加嘛**
如:[1,2,3,4]
解释: [1,2] [3,4]  1+3=4 每组的第一位相加，都不用求最小值了
```
        // JDK自带的双轴快速排序方法
        Arrays.sort(nums);
        int value = 0;
        for (int i = 2; i <= nums.length; i+=2) {
            //初始下标为2,分割数组
            value += nums[i - 2];
        }
        return value;
```

效果:
执行用时 :18 ms, 在所有 java 提交中击败了92.21%的用户
内存消耗 :39.1 MB, 在所有 java 提交中击败了98.03%的用户

**看了大家的题解，发现也可以这样:**
```
        // JDK自带的双轴快速排序方法
        Arrays.sort(nums);
        int value = 0;
        for (int i = 0; i < nums.length; i+=2) {
            //分割数组,然后累加数组的第一位值
            value += nums[i];
        }
        return value;
```
