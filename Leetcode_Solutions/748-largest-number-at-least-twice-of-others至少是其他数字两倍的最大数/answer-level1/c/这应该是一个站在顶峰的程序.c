
![1.png](https://pic.leetcode-cn.com/8142fe24e9fcc8c55baf69928424ddf8dec21ec57433d1874961952f64753d5e-1.png)
```
int judge(int* nums, int numsSize){
    int position, max=0, i;
    for(i=0; i<numsSize; i++){
        if(max < nums[i]){
            max = nums[i];
            position = i;
        }
    }
    for(int j=0; j<numsSize; j++){
        if(j == position) continue;
        if(max < 2*nums[j]) return 0;
    }
    return position+1;
}
int dominantIndex(int* nums, int numsSize){
    return judge(nums, numsSize) ? (judge(nums, numsSize)-1):-1;
}

```


