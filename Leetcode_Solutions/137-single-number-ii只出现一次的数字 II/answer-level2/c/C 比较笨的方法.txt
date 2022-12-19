int singleNumber(int* nums, int numsSize){
    int tmp[32] = {0};
    int i,j;
    long ret=0;
    int flag=0;

    if(!nums||numsSize%3!=1) return 0;

    for(i=0;i<numsSize;i++) {
        for(j=0;j<32;j++) {
            if(nums[i]&1)  tmp[j]++;
            nums[i]=nums[i]>>1;
        }
    }
    if(tmp[31]%3 == 1) {flag = 1;j=30;}
    else j = 31;  

    for(i=j;i>=0;i--) {//负数不计算符号位
        ret += (tmp[i]%3);
        if(i) ret = ret<<1;
    }
    if(flag) {//负数处理，除符号位外-1后再取反，最后取负数
        ret--;
        ret ^=0x7fffffff;
        ret = 0-ret;
    }

    return (int)ret;
}