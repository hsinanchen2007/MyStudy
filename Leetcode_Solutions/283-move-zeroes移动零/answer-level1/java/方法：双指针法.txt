### 解题思路
我们可以放置两个指针 i 和 j，其中 i 是慢指针，而 j 是快指针。只要 nums[j]=0，我们就增加 j 以跳过0项。

当我们遇到 nums[j]≠0 时，跳过0项的运行已经结束，因此我们必须把它（nums[j]）的值复制到 nums[i]。然后递增 i，接着我们将再次重复相同的过程，直到 j 到达数组的末尾为止,再将0赋值给i项及之后的数组即可。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int i = 0;
        for(int j = 0; j < n; j++){
            if(nums[j]!=0)
            nums[i++]=nums[j];
        }

        for(int k = i; k < n; k++) {
			nums[k] = 0;
    }
}
}
```