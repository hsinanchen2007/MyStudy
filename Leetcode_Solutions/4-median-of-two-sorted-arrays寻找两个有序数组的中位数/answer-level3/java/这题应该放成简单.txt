```
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int a=nums1.length;
        int b=nums2.length;
        int[] nums3=new int[a+b];
        for(int i=0;i<a;i++)
            nums3[i]=nums1[i];
        int d=a;
        for(int i=0;i<b;i++){
            nums3[d]=nums2[i];
            d++;
        }
        Arrays.sort(nums3);
        double c=0;
        if((a+b)%2==0){
            double f=nums3[(a+b)/2-1]+nums3[(a+b)/2];
            c=f/2;
        }
        else {
            c=nums3[(a+b)/2];
        }
        return c;
    }
}
```