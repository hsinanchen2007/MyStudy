按序扫描数组，同时使用一个count=0来计数。
1.当扫描到的元素等于val时，则count++，表示下一个不等于val的元素需要往前挪count个位置。
2.当扫描的元素不等于val时，该元素往前挪count个位置
3.扫描结束后返回numsSize-count

int removeElement(int* nums, int numsSize, int val){
    if(numsSize==0){
        return 0;
    }
    int i=0,count=0;
    while(i<numsSize){
        if(nums[i]==val){
            i++;
            count++;
        }else{
            nums[i-count]=nums[i];
            i++;
        }
    }
    return numsSize-count;
}
