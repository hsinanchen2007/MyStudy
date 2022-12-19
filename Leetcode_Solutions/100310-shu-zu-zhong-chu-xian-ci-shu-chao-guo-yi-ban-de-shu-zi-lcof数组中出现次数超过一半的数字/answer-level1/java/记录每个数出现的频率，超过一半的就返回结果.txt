```
class Solution {
    public int majorityElement(int[] nums) {
        int len=nums.length,res=0;
        HashMap<Integer,Integer>map=new HashMap<>();
        for(int i=0;i<len;i++){
            if(map.containsKey(nums[i])){
                //int temp=map.get(nums[i])+1;
                map.put(nums[i],map.get(nums[i])+1);
            }else{
                map.put(nums[i],1);
            }
            if(map.get(nums[i])>len/2){
                res=nums[i];
                break;
            }
        }
        return res;
    }
}
```
