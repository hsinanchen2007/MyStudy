实在想不出怎么用栈。哪位大神想到了。告诉我下，不胜感激
```
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int a[]=new int[nums1.length];
        for(int i=0;i<nums1.length;i++){
            int m=0;
            boolean flag=false;
            for(int j=0;j<nums2.length;j++){
                if(nums2[j]==nums1[i]){
                    m=j;
                }
            }
            for(int k=m;k<nums2.length;k++){
                if(nums2[k]>nums1[i]){
                    flag=true;
                    a[i]=nums2[k];
                    break;
                }
            }
            if(!flag){
                a[i]=-1;
            }
        }
        return a;
    }
    
}
```
