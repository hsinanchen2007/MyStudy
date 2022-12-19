class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
       int lenth = n+m-1;
        m--;
        n--;
       
            for (int i = lenth; i>=0 ; i--) {
                if(m==-1){
                        for(int k =0;k<=n;k++){
                            nums1[k]=nums2[k];
                        }
                        break;
                    }
                    else if(n==-1){
                        break;
                    }
                if (nums1[m]>=nums2[n]){
                    nums1[i]=nums1[m];
                    m--;
                }else{
                    nums1[i]=nums2[n];
                    n--;
                }
           
                    
            }
        
        
    }
}