### 解题思路
这种解法失去了本题的灵魂
### 代码

```java
class Solution {
    private int[] nums;
    Map<Integer,Integer>map;
    public Solution(int[] nums) {
        this.nums=nums;
        this.map=new HashMap<>();
    }
    public int pick(int target) {
        int index=0;
        Random random = new Random();
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                map.put(index,i);
                index++;
            }
        }
        int i2 = random.nextInt(index);
        return map.get(i2);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
```