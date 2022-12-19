### 解题思路
排序后用双指针遍历数组。双指针可以很好地利用有序性这一条件，故先将数组排序，定义两个指针i、j，分别指向数对的前、后两个数。i从0开始，j从1开始。遍历数组找出所有满足条件的数对，保持i、j指向每一数对的前后两个数，通过不断后移指针，直到扫描完整个数组。
但是使用双指针的过程中，有许多需要注意的细节：
- 特判k<0的情况，k是两数之差的绝对值，k小于0可直接返回。
- i、j可能在移动的过程中指向同一元素，这会发生在k==0的情况下，这不满足数对的要求（需要两个数），此时j++。
- 重复数对不予计数，只计算不同的数对的数量。使用一个last变量，记录上一数对，防止重复。

时间复杂度：O(nlogn)。排序O(nlogn)，双指针扫描O(n)。
空间复杂度：O(1)。双指针使用常数空间。

### 代码

```java
class Solution {
    public int findPairs(int[] nums, int k) {
        if(k<0) return 0;
        Arrays.sort(nums);
        int i=0,j=1;
        int last=-1;
        int count=0;
        while(i<nums.length && j<nums.length)
        {
            if     (nums[i]+k<nums[j])  i++;
            else if(nums[i]+k>nums[j])  j++;
            else 
            {
                if(i!=j)
                {
                    if(last==-1 || (last!=-1 && nums[last]!=nums[i]))
                    {
                        count++;
                        last=i;
                    }
                    i++;
                    j++;
                }
                else
                    j++;
            }
        }
        return count;
    }
}
```