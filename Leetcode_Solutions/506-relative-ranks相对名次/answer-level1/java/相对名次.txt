### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String[] findRelativeRanks(int[] nums) {
    String []num=new String[nums.length];
    int []sum=nums.clone();
    Arrays.sort(sum);
    Map<Integer,Integer> map=new HashMap<Integer,Integer>();
    for(int i=0;i<sum.length;i++){
            map.put(sum[i],i);
    }
    for(int i=0;i<nums.length;i++){
        if(map.get(nums[i])==nums.length-1)
         num[i]="Gold Medal";
         else  if(map.get(nums[i])==nums.length-2)
         num[i]="Silver Medal";
         else if(map.get(nums[i])==nums.length-3)
         num[i]="Bronze Medal";
         else num[i]=(nums.length-map.get(nums[i]))+"";
    }
    return num;
    }
}
```