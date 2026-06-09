这种方法处理数值范围较小的数字集合还行
```
#define N 99999//由最大数或最小数决定
int singleNumber(int* nums, int numsSize){
   int a[2 * N + 1] = {0};
   int i;

   for (i = 0; i < numsSize; i++){
       a[nums[i] + N]++;
   }
   for (i = 0; i < 2 * N + 1; i++){
       if (a[i] != 1)
        continue;
       else
        break;
   }
   return (i - N);
}
```
