 ### 当位置和次数都重要时，请采用多个hashMap
### 当位置和次数都重要时，请采用多个hashMap
### 当位置和次数都重要时，请采用多个hashMap

### 代码

```java
class Solution {//次数和位置同样重要时，应该建立2个hashmap!!!

    public int findShortestSubArray(int[] nums) {
        HashMap<Integer,Integer> left=new HashMap<>(),right=new HashMap<>(),count=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(left.get(nums[i])==null) left.put(nums[i],i);
            right.put(nums[i],i);
            count.put(nums[i], count.getOrDefault(nums[i],0)+1);
        }
        int res=nums.length;
        int degree=Collections.max(count.values());
        for(int x:count.keySet()){
            if(count.get(x)==degree) res=Math.min(res,right.get(x)-left.get(x)+1);
        }
        return res;
    }
}
```