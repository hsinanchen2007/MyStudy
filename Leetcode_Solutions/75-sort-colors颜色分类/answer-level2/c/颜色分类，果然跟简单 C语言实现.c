还排啥序啊～～～
重写数组就好了。

```c
void sortColors(int* nums, int numsSize){
   int i, j, *p = nums;
    int count[3] = {0,0,0};
    for(i=0;  i<numsSize; i++){
        count[nums[i]]++;
    }
    for (j=0; j < 3; j++)
     for(i=0;  i<count[j]; i++){
        *p++=j;
    }
}
```
