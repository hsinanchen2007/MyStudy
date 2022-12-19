### 解题思路
当target大于最后元素的值时，取len+1；
条件用while（left<right） 则当跳出循环时一定有left=right，此时返回left和返回right结果是一样的；
mid有两种取值：
    1>当数组元素个数为偶数时，mid=(left+right) >>> 1  返回的是左中位数； mid=(left+right+1) >>> 1  返回的是右中位数；
    2>当数组元素个数为奇数时，mid=(left+right) >>> 1 和 mid=(left+right+1) >>> 1 结果是一样的；
所以运用模板，则根据分支逻辑，设定mid表达式。
如以下代码，分支是target>nums[mid]，则mid表达式应为mid=(left+right) >>> 1，此时mid要么是左中位数，要么正好是中位数。
结果返回left和right都行。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        if(target>nums[right])
            return right+1;
        while(left<right){
            int mid=(left+right) >>> 1;
            if(target>nums[mid])
                left=mid+1;
            else 
                right=mid;
        }
        return left;
    }
}
```