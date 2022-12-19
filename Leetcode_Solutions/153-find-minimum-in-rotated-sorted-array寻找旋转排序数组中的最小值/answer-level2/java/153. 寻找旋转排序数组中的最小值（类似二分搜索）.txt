### 解题思路
本体主要思路就是类似于二分搜索
因为递增数据在某一点被反转，考虑两种情况。
（1） 在数据的两端进行翻转的，数据顺序不会发生变化，nums[0]即是最小值
（2） 在数据的中间某部分进行翻转的
主要是考虑第二种情况，在第二种情况下，很显然不管在哪一点进行的的反转，此时首位的值必然是大于最右边的数值，**数据被划分为了两个递增序列**
如下所示：
未翻转前 |1|2|3|4|5|6|7|8| 
翻转后数据（4为翻转点） |5|6|7|8| 1|2|3|4|   
显然 5（nums[0]） 大于4(nums[nums.length-1]) ，
**且左边的递增序列不可能存在最小值，最小值存在于右边的递增序列的最左节点**

如此我们可以采用类似二分搜索的方法.
步骤如下：
(1) 初始化 low=0,higth=nums.length-1;、
(2) 判断low<hing 是否成立，成立进入（2），否则跳转到（5）
(2) mid= (low+higth)/2    `//跟二分搜索一样`
(3) 若nums[mid] 的值大于尾部的值， 则说明，mid处于左边的递增序列，显然mid左侧的值均是大于尾部的，不可能是最小值，此时low=mid+1. ，进入（5）。若不符合进入（4），
(4) 反之，若nums[mid]的值小于或者等于最右边的值，则说明mid处的结点存在于右边的递增序列中，**mid右边的结点中不可能存在最小值，最小值在其左边或者是其自身**，此时令 high=mid; 进入（2）
(5) 返回 nums[low] ,即是所求最小值
`

### 代码

```java
class Solution {
   public int findMin(int[] nums) {
        int low=0,high=nums.length-1,mid;
//        说明翻转后的数据没有变化
        if(nums[low]<=nums[nums.length-1])return nums[low];

        while (low<high){
            mid=(low+high)/2;
//            当前值大于最右边
            if (nums[mid]>nums[nums.length-1]){
                low=mid+1;
            }else {//nums[mid]<=nums[nums.length-1]
                high=mid;
            }
        }
        return nums[low];

    }
}
```