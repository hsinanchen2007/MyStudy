
```Java
class Solution {
    public int search(int[] nums, int target) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        int value = 0;
        map.put(target,value);
        for(int i = 0;i< nums.length;i++){
            if(map.containsKey(nums[i])){
                value++;
                map.put(target,value);
            }
        }
        return map.get(target);
    }
}
```
![Screen Shot 2020-03-24 at 2.31.19 PM.png](https://pic.leetcode-cn.com/d99189eec69665035483d23aa4785e0055f3b23cc51d8d431f3fcabbcccbacab-Screen%20Shot%202020-03-24%20at%202.31.19%20PM.png)
