```
#define MAX_SIZE 100000
int book[MAX_SIZE] = {0};
int DFS(int* nums, int numsSize, int target) {
    int sum = 0;
    if (target == 0) {
        return 1;
    } 
    if (target < 0) {
        return 0;
    }
    if (book[target] != -1) {
        return book[target];
    }
    for (int i = 0; i < numsSize; i++) {
        sum += DFS(nums, numsSize, target - nums[i]);
    }
    book[target] = sum;
    return sum;
}
int combinationSum4(int* nums, int numsSize, int target){
    if (numsSize == 0) {
        return 0;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        book[i] = -1;
    }
    return DFS(nums, numsSize, target);
}
```
