
### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
	if(A.length<3)
			 return false;
		 int left=Integer.MAX_VALUE;
		 int mid=Integer.MAX_VALUE;
		 int right=Integer.MAX_VALUE;
		 int i=0,j=A.length-1;
		 int sum=0;
		 for(int k=0;k<A.length;k++){
			 sum=sum+A[k];
		 }
        if(sum%3!=0)
        return false;
		 int subSum=sum/3;
		 for(;i<j;i++){
			 if(left!=subSum){
				 if(i==0)
					 left=A[0];
				 else
				 left=left+A[i];
			 }
			 if(left==subSum)
			 {
				break; 
			 }
		 }
		 for(;j>i;j--){
			 if(right!=subSum){
				 if(j==A.length-1)
					 right=A[j];
				 else
				 right=right+A[j];
			 }
			 if(right==subSum){
				 break;
			 }
		 }
         if(i+1==j)
         return false;
		 for(int k=i+1;k<j;k++){
			 if(k==i+1)
			 {
				 mid=A[k];
			 }
			 else
			 mid=mid+A[k];
		 }
		 
	     if(mid==subSum)
	    	 return true;
	     return false;
	   
    }
}
```