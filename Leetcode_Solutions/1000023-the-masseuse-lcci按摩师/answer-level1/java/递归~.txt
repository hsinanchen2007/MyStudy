### 解题思路
递归，用map保存所有解

### 代码

```java
class Solution {
    static Map<Integer,Integer> way;

    public static int massage(int[] nums) {
      if (nums.length == 0) {
            return 0;
        }
        way= new HashMap();
        return find(nums, nums.length);
 }

    public static int find(int[] nums,int i) {
    	if(way.containsKey(i)) {
    		return way.get(i);
    	}
        if(nums.length==1){
        	way.put(i, nums[0]);
            return nums[0];
        } 
        
        if(nums.length==2){
        	way.put(i, Math.max(nums[0],nums[1]));
            return Math.max(nums[0],nums[1]);
        } 
            int[] aa=Arrays.copyOf(nums, nums.length-2);
            int[] bb=Arrays.copyOf(nums, nums.length-1);
            int cc=Math.max(find(aa,aa.length)+nums[nums.length-1],find(bb,bb.length));
             way.put(i, cc);
            return cc;
        
    }
}
```