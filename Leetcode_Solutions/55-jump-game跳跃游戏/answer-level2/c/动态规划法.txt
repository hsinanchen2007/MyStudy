bool canJump(int* nums, int numsSize){

 if(numsSize==0){
    return false;
}
if(numsSize==1){
    return true;
} 
if(numsSize==2){  
    if(nums[0]!=0) {
        return true;
    }else {
    return false;   
    }
}
int temp=nums[0];
if(temp==0){
return false;
}
else{
if(temp>=numsSize-1){
return true;
}
for(int i=temp;i>0;i--){
    if(nums[i]<=temp-i){
        continue;
    }
int *tempNums;    
tempNums=&nums[i];

        if(canJump(tempNums, numsSize-i)==true){
            return true;
        }
       // printf("%d\n",i);
    }
    return false;
    
}
}