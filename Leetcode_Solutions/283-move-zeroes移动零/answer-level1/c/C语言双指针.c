### 解题思路

依旧是好用的双指针思路，一个指针指向0的位置，一个指向不为0的位置。

我们不但可以是先把0放在最后，也是实现把0放在最前。

如果把0放在最后，那就是每次移动指向0的指针，如果不为0，就和指向不为0的位置交换，然后指向不为0的指针往后移动。

如果把0放在前面，那就是每次移动指向不为0的指针，如果发现为0，就交换，然后为0的指针往后移动。

双指针awesome！

### 代码

```c
void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize){

    if ( numsSize < 2 ) return nums;
    int zero_pos = 0;
    int non_zero_pos = 0;
    while ( zero_pos < numsSize){
        if (nums[zero_pos] != 0 ){
            swap(&nums[zero_pos], &nums[non_zero_pos]);
            non_zero_pos++;
        }
        zero_pos++;
    }
    return nums;
}


```