```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();
        for(int i=0;i<nums1.length;i++) set1.add(nums1[i]);
        for(int i=0;i<nums2.length;i++) set2.add(nums2[i]);
        LinkedList<Integer> list = new LinkedList<>();
        
        for(int num : set1){
            if(set2.contains(num)) list.add(num);
        }
        int[] ret = new int[list.size()];
        for(int i=0;i<list.size();i++){
            ret[i] = list.get(i).intValue();
        }
        return ret;
    }
}
```
