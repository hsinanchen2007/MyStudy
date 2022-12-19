将每个元素以及所在位置存入到hashmap中，判断当前位置到元素是否存在于map中，如果存在，则比较当前位置与所记录的位置的绝对值是否小于等于k，如果小于，则返回true。

注意，此处是需要注意的地方，如果当前位置与所记录的位置的绝对值并不是小于等于k，则将最新的位置记录下来，因为后续可能还存在相同的元素，需要对比位置


```
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
 		 boolean value=false;
 		 for(int i=0;i<nums.length;i++){
 			 if(map.containsKey(nums[i])) {
 				if(i-map.get(nums[i])<=k) {
 					value = true;
 				}else{
                    map.put(nums[i], i);
                }
 				 
 			 }else {
 				 map.put(nums[i], i);
 				
 			 }
 	            
 	        }
 		return value;
    }
}
```
