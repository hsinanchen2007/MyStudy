```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int k=0;
        ArrayList<Integer> listA = new ArrayList<>();
         ArrayList<Integer> listB = new ArrayList<>();
            for (int a : nums1) {
                listA.add(a);
            }
            for (int b : nums2) {
                listB.add(b);
            }
            listA.retainAll(listB);
            Set<Integer> set=new HashSet<Integer>();
            for(int i:listA){
                set.add(i);
            }
            int[] answer=new int[set.size()];
            for(int i:set){
                answer[k]=i;
                k++;
            }
            return answer;
    }
}
```
