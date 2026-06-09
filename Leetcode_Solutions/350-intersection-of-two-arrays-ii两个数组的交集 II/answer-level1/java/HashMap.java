```
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap <Integer, Integer> hm = new HashMap();
        List <Integer> list = new ArrayList();
        for(int i = 0; i < nums1.length; i++){
            hm.put(nums1[i], hm.getOrDefault(nums1[i], 0) + 1);
        }
        for(int i = 0; i < nums2.length; i++){
            if(hm.containsKey(nums2[i]) && hm.get(nums2[i]) > 0){
                list.add(nums2[i]);
                hm.put(nums2[i], hm.get(nums2[i]) - 1);
            }
        }
        int [] arr = new int [list.size()];
        for(int i = 0; i < list.size(); i++){
            arr[i] = list.get(i);
        }
        return arr;
    }
}
```
