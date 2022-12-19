### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        //由于找的是超过三分之一的元素，那么最多是有两个元素的，我们找第一多和第二多的元素。看一下它们是否满足题意
        List <Integer> ret=new ArrayList<>();
        if(nums.length==0||nums==null)
            return ret;
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int count=map.getOrDefault(nums[i],0);
            if(count==nums.length/3)
                ret.add(nums[i]);  //此时加上这个数就超过了三分之一
            if(count==2*nums.length/3||ret.size()==2)  //最多有两个元素符合
                return ret;
            map.put(nums[i],count+1);
        }
        return ret;
    }
}
```