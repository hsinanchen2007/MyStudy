
bool containsDuplicate(int* nums, int numsSize){
     int d;
	 int i,j,t;
	 for (d=numsSize/2;d>0;d/=2)
	 {
		 for (i=d;i<numsSize;i++)
		 {
			 t=nums[i];
			 for (j=i-d;j>=0&&t<nums[j]; j-=d)
			 {
				 nums[j+d]=nums[j];
			 }
			 nums[j+d]=t;
		 }
	 }
    for(i=0;i<numsSize-1;i++){
       if(nums[i]==nums[i+1])
           return true;
    }
    return false;
}
