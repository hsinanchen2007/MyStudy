找到第一个满足nums[m] > nums[m+1]条件的 m,这个值(nums[m])必定是峰值(充分理解这句话)
我们知道二分法的结果（目的）是找一个**边界值**, 找什么样子的边界值就体现在二分算法中的if语句中
就是下面的` if (nums[m] > nums[m+1])`语句

具体代码如下：
```Java
public int findPeakElement(int[] nums) {
    if (nums.length == 0) return -1;
    if (nums.length == 1) return 0;
    int l = 0, r = nums.length - 1;
    int m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (nums[m] > nums[m+1]) r = m;
        else l = m + 1;
    }
    return l;
}
```

如果有不懂的可以留言评论

这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！