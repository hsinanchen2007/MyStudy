### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++)
        {
            if(map.containsKey(nums[i]))
            {
                map.put(nums[i], map.get(nums[i])+1);           
            }
            else
            {
                map.put(nums[i],1);
            }
        }
        int res=0;
        int cur=0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (map == null || entry.getValue()>cur) {
                res = entry.getKey();
                cur=entry.getValue();
            }
        }
        return res;
    }
}
```