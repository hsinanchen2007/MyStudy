![0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png](https://pic.leetcode-cn.com/77959ddaf1b79edc236cf52240e74b63c342bb0a8160f158095383b4117d2a54-0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png)


### 解题思路


### 代码

```c
int comp(int *a, int *b){
    return *a < *b;
}
int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), comp);
    return nums[k-1];
}
```