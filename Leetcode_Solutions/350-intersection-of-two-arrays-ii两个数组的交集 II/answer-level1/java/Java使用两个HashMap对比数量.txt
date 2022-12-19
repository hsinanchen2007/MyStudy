
```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> map1 = new HashMap<Integer,Integer>();
        HashMap<Integer,Integer> map2 = new HashMap<Integer,Integer>();
        for(int num : nums1){
            map1.put(num, map1.getOrDefault(num, 0) + 1);
        }
        for(int num : nums2){
            map2.put(num, map2.getOrDefault(num, 0) + 1);
        }
        int i = 0;
        for(int num : map1.keySet()){
            int count1 = map1.getOrDefault(num, 0);
            int count2 = map2.getOrDefault(num, 0);
            int count = Math.min(count1, count2);
            while(count-- > 0){
                nums1[i++] = num;
            }
        }
        return Arrays.copyOfRange(nums1, 0, i);
    }
}
```
