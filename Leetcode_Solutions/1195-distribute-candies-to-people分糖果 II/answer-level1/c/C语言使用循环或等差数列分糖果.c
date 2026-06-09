**下面两种方法的详解请看leetcode官方思路解释**
# 方法一：循环发糖，直至糖果发完
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *nums = (int *)calloc(num_people, sizeof(int));
    int offset = 0;
    while (candies != 0) {
        for (int i = 0; i < num_people; i++) {
            if (candies > offset + i + 1) {
                nums[i] += offset + i + 1;
                candies -= offset + i + 1;
            }
            else {
                nums[i] += candies;
                candies = 0;
                break;
            }    
        }
        offset += num_people;
    }
    *returnSize = num_people;
    return nums;
}
```
# 方法二：使用等差数列求和
```
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *nums = (int *)calloc(num_people, sizeof(int));
    int p = (int)floor(sqrt(2 * candies) - 0.5);
    int rows = p / num_people;
    int cols = p % num_people;
    int remain = candies - p * (1 + p) / 2;

    for (int i = 0; i < num_people; i++) {
        nums[i] = (i + 1) * rows + num_people * rows *(rows - 1) / 2; 
    }
    for (int i = 0; i < cols; i++) {
        nums[i] += (i + 1) + num_people * rows;
    }
    nums[cols] += remain;

    *returnSize = num_people;
    return nums;
}
```

