### 解题思路
【对数组的长度进行判断】
先将数组排序，则相同元素肯定排在一起，将数组元素添加到hash表中的同时，判断元素出现的个数，当有元素出现次数为(nums.length)/2+1时，主要元素出现。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if(nums==null|nums.length==0)  return -1;
        if(nums.length==1)  return nums[0];
        Arrays.sort(nums);
        int len=(nums.length)/2+1;
        int i=1;
        Set<Integer>set=new HashSet<Integer>();
        for(int num:nums){
            if(!set.add(num)) {
                i++;
                if(i==len) return num;
            } 
            else i=1;
        }
        return -1;
    }
}
```