```
void reverse(int *nums,int left, int right){
    while(left<right){
        int tmp = nums[left];
        nums[left]= nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k){
    if(k&&k<numsSize){
        int left = 0;
        int right = numsSize-k;
        int lenght = numsSize;
        reverse(nums,left,right-1);
        reverse(nums,right,numsSize-1);
        reverse(nums,left,numsSize-1);
    }else if(k>numsSize){
        int step = k%numsSize;
        rotate(nums,numsSize,step);
    }
}
```
先将数组切割,随后对两个部分分别做逆置变换,最后对逆置的数组整体再做一次逆置.
又一个坑值得注意,就是如果k>numsize的情况,实际上就是对数组做k=k%numsSize的相应变换.
