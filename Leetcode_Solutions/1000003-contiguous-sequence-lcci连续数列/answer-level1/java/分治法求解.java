### 解题思路
本题最好的解法当然是动态规划，这里不做说明
看到进阶说明要求用分治，尝试多次终于通过
注意：分治法使用较多的局部变量，因此需要格外注意变量命名（因为变量名弄混导致了两次通不过，手动狗头。。。。）

对一个整数数组求总和最大的连续数列
按照分治的思想，我们将整个大数组分为左半数组(left, mid)，右半数组(mid + 1, right)
这时对于整个数组而言，求和最大的连续数列出现位置仅有三处
1.左半数组，这种情况的最大和我们可以通过递归求出，参数(nums, left, mid)
2.右半数组，这种情况的最大和我们同样可以通过递归求出，参数(nums, mid + 1, right)
3.中间横跨mid的数组，这种情况需要我们深究，下面进行详细介绍

对于第三种位置情况，我们求和时必须保证其不与前两种情况重合，必须保证此处的求和数列必须横跨mid
为保证这点，我们初始化crossSum = nums[mid] + nums[mid + 1]
然后先左再右(或者先右后左)在crossArrayLeft >= left(crossArrayRight <= right)的前提下使crossSum最大
注意：这里不能根据数本身的正负来决定是否加入cross数组，且我们必须遍历到该层递归数组的边界值，即left，right

最后找出3种位置得到的最大和的最大值,return
### 代码

```java
class Solution {
    /**
     * @param nums An array of integers (both positive and negative)
     * @return Find the contiguous sequence with the largest sum
     */
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length == 0) return -1;

        return subArraySum(nums, 0, nums.length - 1);
    }

    private int subArraySum(int[] nums, int left, int right) {
        if(left == right) return nums[right];

        int mid = left + ((right - left) >>> 1);
        int leftSum = subArraySum(nums, left, mid);
        int rightSum = subArraySum(nums, mid + 1, right);
        int crossSum = nums[mid] + nums[mid + 1];
        
        int temp = crossSum;
        int crossArrayLeft = mid - 1;
        int crossArrayRight = mid + 2;
        while(crossArrayLeft >= left) {
            temp += nums[crossArrayLeft];
            crossArrayLeft--;
            if(temp > crossSum) crossSum = temp;
        }
        temp = crossSum;
        while(crossArrayRight <= right) {
            temp += nums[crossArrayRight];
            crossArrayRight++;
            if(temp > crossSum) crossSum = temp;
        }
        
        return Math.max(Math.max(leftSum, rightSum), crossSum);
    }
}
```