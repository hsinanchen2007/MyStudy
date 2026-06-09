### 解题思路
基本没刷过题。。。所以方法比较笨。简单介绍一下，一开始是先排序让这个数组变得有序，排序后，我们从1开始循环，nums[0]的值我们已知。
如果，nums[i] == nums[i-1]的话呢，就说明我们找到了两个相同的数，这时我们i++，然后循环体再i++；就跳了两个量，再用这个方法，继续检查
如果不相等的话，那么nums[i-1]就是我们要的答案。
第一次写题解，讲述不清的地方多多包涵。

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1;i < nums.length;i++){
            if(nums[i] == nums[i-1]){
                i++;
            }
            else{
                return nums[i-1];
            }
        }
        return nums[nums.length - 1];
    }
}
```