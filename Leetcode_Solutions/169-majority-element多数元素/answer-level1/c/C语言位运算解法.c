参照评论区里的位运算解法写了个c语言版本的
其中部分代码写法拙劣，还请大神指教

```
int majorityElement(int* nums, int numsSize){
    int result =0,k = numsSize/2,flag=0;
    for(int i=0;i<32;i++){ //int类型占4字节（共32位）
        int count=0,j=0;
        flag=0;
        for(;j<numsSize;j++){
            if(nums[j]<0){
                count += ~nums[j] >> i & 1; //将num[j]二进制形式的值右移i位，然后用位运算符&和掩码1结合
                flag++;
            }
            else
                count += nums[j] >> i & 1;
            if(count>k){
                result += 1<<i;
                break;
            }
        }
    }  
return flag>k?-result-1:result;
}

```
