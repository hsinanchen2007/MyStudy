### 解题思路
对于每一个二进制位，1出现的次数要么是3的倍数，要么是3的倍数加1，如果是后者那说明出现一次的数字在这位上是1.

### 代码

```c
int singleNumber(int* nums, int numsSize){
    int result = 0;
    for(int i=0;i<32;i++){
        long count =0;        //不用long，力扣的编译器不通过，不让int类型左移31位...
        for(int j=0;j<numsSize;j++){
            count += (nums[j]>>i)&1;
        }
        result += (count%3)<<i;
    }
    return result;
}
```