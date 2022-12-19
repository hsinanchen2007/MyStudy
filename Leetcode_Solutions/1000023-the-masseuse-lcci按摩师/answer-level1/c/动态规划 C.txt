### 解题思路
动态规划， 速度O(N), 内存O(1)

### 代码

```c
int max(int a, int b){
    if(a>=b) return a;
    else return b;
}


int massage(int* nums, int numsSize){
    int book = 0;
    int non_book = 0;
    int result = 0;
    for(int i = 0; i < numsSize; i++){
        int tmp = non_book;
        non_book = max(book,non_book);
        book = tmp+nums[i];
    } 
    result = max(book, non_book);
    return result;
}
```