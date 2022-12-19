class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        int m=nums1.length;
        int n=nums2.length;
        int a=0;
        if(m==0&&n==0){
        return 0.0;
        }
        
        if(m>n){
            int[] temp=nums1;
            nums1=nums2;
            nums2=temp;
            a=m;
            m=n;
            n=a;
        }
        
        int begin=0;
        int end=m;
        int t=(n+m+1)/2;
        int i=0;
        int j=0;
        double answer=0.0;
        while(begin<=end){
            i=(begin+end)/2;
            j=t-i;
            if(i>0&&nums1[i-1]>nums2[j])
            end=i-1;
            else if(i<m&&nums2[j-1]>nums1[i])
            begin=i+1;
            else{
                 int left=0;
                 
                if(i==0)
                left=nums2[j-1];
                else if(j==0)
                left=nums1[i-1];
                else {
                     left=Math.max(nums1[i-1],nums2[j-1]);
                }
                if((m+n)%2==1){
                    return left;
                }
                int right=0;
                if(i==m)
                right=nums2[j];
                else if(j==n)
                right=nums1[i];
                else {
                    right=Math.min(nums1[i],nums2[j]);
                }
                
                return (left+right)/2.0;
                
            }
           
        }
      return 0.0;   
        
    }
}