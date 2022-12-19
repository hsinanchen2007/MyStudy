先对两个数组排序后遍历
排序的时间O(nlog(n))
遍历的时间为O(n)
```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if(nums1.length==0&&nums2.length==0){
            return new int[0];
        }
        // 对数组排序
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer> res=new ArrayList<>();
        int i=0,j=0;
        while(i<nums1.length&&j<nums2.length){
            if(nums1[i]==nums2[j]&&!res.contains(nums1[i])){
                res.add(nums1[i]);
                i++;j++;
            }else{
                if(nums1[i]<nums2[j])            
                    i++;
                else
                    j++;
            }
        }
        int[] ress=new int[res.size()];
        for (int k = 0; k < res.size(); k++) {
            ress[k]=res.get(k);
        }
        return ress;
    }
}
```
