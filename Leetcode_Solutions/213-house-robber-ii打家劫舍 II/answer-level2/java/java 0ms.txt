class Solution {
    public int rob(int[] nums) {
        
         int v1=0;
        int v2=0;
        if(nums==null) return 0;
        if(nums.length==1) return nums[0];
        if(nums.length==2) return Math.max(nums[0],nums[1]);
    
        int len=nums.length;
        if(len==0) return 0;
        int[]a=new int[len + 1];
        a[0]= 0;
        a[1]=nums[0];
        for(int i=2;i<=len;i++){
            a[i]=Math.max(a[i-1],a[i-2]+nums[i-1]);
        }
        int []b= new int[len+1];
        b[0]=0;
        b[1]=0;
        for(int j=2;j<len+1;j++){
            b[j]=Math.max(b[j-1],b[j-2]+nums[j-1]);
        }
        
        
        
        
        return Math.max(a[len-1],b[len]);
    
        
        
        
    }
}