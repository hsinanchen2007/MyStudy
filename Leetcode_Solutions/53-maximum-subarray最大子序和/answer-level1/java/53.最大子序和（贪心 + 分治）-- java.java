
解法一 贪心法

思路：只有前面连续子序列之和sum大于0，sum + 后面的数才有可能是最大值。
但是数组中所有元素有可能都是负数，所以最大值max 的初始值不能从0开始，具体步骤见代码。


```java

public int maxSubArray(int[] nums) {
    int max = Integer.MIN_VALUE;
    int sum = 0;
    for(int i=0; i<nums.length; i++) {
        sum += nums[i];
        max = Math.max(sum, max);
        if(sum < 0) sum = 0;
    }
    return max;
}

```

解法二 分治法

思路：对数组中的元素进行二分
1. 求二分后左边元素的最大连续子序列和 maxLeft
2. 求二分后右边元素的最大连续子序列和 maxRight
3. 求 (以切分点为右端点且往左的最大连续子序列和 + 切分点为起始点往右最大连续子序列和) maxMid
4. 比较maxLeft 、maxRight、maxMid之间的最大值作为当前分治子问题的最大子序列和

```java
public int maxSubArray(int[] nums) {
    return maxSubArray(nums, 0, nums.length-1);
}

private int maxSubArray(int[] nums, int left,int right) {
    if(left == right) return nums[left];
	
    int mid = (left+right) >>> 1;
    int midLeftMax = nums[mid], midRightMax = nums[mid+1], midleft = midLeftMax, midright = midRightMax;
    int leftMax = maxSubArray(nums, left, mid);
    int rightMax = maxSubArray(nums, mid+1, right);
	
    for (int i = mid-1; i >= left; i--) {
        midLeftMax = Math.max(midleft += nums[i], midLeftMax);
    }
    for (int i = mid+2; i <= right; i++) {
        midRightMax = Math.max(midright += nums[i], midRightMax);
    }
	
    return Math.max(Math.max(leftMax, rightMax), midLeftMax + midRightMax);
}
```
