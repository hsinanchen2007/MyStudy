### 解题思路
利用HashMap实现
### 代码
```java
class Solution {
    HashMap<Integer,List<Integer>> mp = new HashMap<Integer,List<Integer> >();
    public Solution(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            if(mp.containsKey(nums[i]) == false){
                List<Integer> list = new ArrayList<Integer>();
                list.add(i);
                mp.put(nums[i],list);
            }else{
                mp.get(nums[i]).add(i);
            }
        }
        
    }
    
    public int pick(int target) {
        Random r = new Random();
        int random = r.nextInt(mp.get(target).size());
        System.out.println(random); 
        return mp.get(target).get(random);
    }
}
