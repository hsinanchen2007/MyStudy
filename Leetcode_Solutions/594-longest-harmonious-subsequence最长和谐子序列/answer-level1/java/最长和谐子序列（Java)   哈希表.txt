### 解题思路
此处撰写解题思路

### 代码

```java
//首先注意题目要求：子序列的最大、最小值相差正好是1，多了少了都不行。返回两个相邻子序列的长度。所以不是小于等于1，而是子序列最大最小差值必须等于1。
class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer,Integer> map= new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            if(map.containsKey(nums[i]))
                map.put(nums[i],map.get(nums[i])+1);
            else
                map.put(nums[i],1);
        }
        if(map.size()<=1)   
            return 0;
        int max=0;
        int tmp=0;
        for(Integer key :map.keySet())
        {
            if(map.containsKey(key-1))
            {
                tmp=map.get(key)+map.get(key-1);
                max=max>tmp? max:tmp;
            }
        }
        return max;
    }
}
```