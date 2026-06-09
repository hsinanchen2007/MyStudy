思路：将数组1放入集合1，将数组中出现在集合1中的元素放入集合2，将集合2转为数组，返回。
```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer>set1=new HashSet<>();
        Set<Integer>set2=new HashSet<>();
        for(int i=0;i<nums1.length;i++){
            set1.add(nums1[i]);
        }
        for(int j=0;j<nums2.length;j++){
            if(set1.contains(nums2[j])){
                set2.add(nums2[j]);
            }
        }
        int[] res=new int[set2.size()];
        int i=0;
        for(int e:set2){
            res[i++]=e;
        }
        return res;
    }
}
```
执行用时 :3 ms, 在所有 Java 提交中击败了96.51%的用户
内存消耗 :36.8 MB, 在所有 Java 提交中击败了46.63%的用户