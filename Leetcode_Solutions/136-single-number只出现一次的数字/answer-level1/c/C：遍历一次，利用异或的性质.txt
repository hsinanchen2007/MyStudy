理由：异或的性质
（1）a ^ a = 0（一个数和自身异或，结果为0）； 
（2）b ^ 0 = b（一个数与0异或，结果为自身）；
结果默认为首项，遍历时结果与每一项异或，出现两次的项会异或为0，
最终结果为只出现一次的那一项
```
int singleNumber(int* nums, int numsSize){
    int result = nums[0];
    for(int i = 1; i < numsSize; i++){
        result ^= nums[i];
    }
    return result;
}
```
