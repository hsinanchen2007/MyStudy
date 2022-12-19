### 解题思路
此处撰写解题思路

核心就是排序数组，同时为了避免nums中有一些负数的边界因素来添加判断条件，所以直接排序后过滤掉负数，然后将边缘条件剔除，顺序遍历数组即可。
![zx.png](https://pic.leetcode-cn.com/fd70448fa1910a473a469da518647c7579f294b74a4accfdcb941873dca9ce7d-zx.png)


### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        //排序，过滤
        // nums = Arrays.stream(nums).filter(a -> a>0)
        // .sorted().collect(Collector.toList()).toArray(new Integer[list.size()]);
        Arrays.sort(nums);
        int[] nums1 = new int[nums.length];
        int count = 0;
        for(int i = 0;i<nums.length;i++){
            if(nums[i] > 0){
                nums1[count] = nums[i];
                count++;
            }
        }
        if(nums1==null || nums1.length <= 0 || nums1[0] > 1){
            return 1;
        }
        int a= 0;
        for(int i =1; i < nums1.length; i++){
            if(nums1[i] - nums1[i-1] > 1){
                return nums1[i-1] +1;
            }
            if(nums1[i]>0){
                a++;
            }
        }
        return nums1[a]+1;
    }
}
```