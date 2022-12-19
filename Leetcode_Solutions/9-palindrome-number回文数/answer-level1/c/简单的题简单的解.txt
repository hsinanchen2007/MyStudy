### 解题思路
按位拆开到数组再比较

### 代码

```c
bool isPalindrome(int x){
    if(x < 0)
        return false;
    int nums[10] = {0};
    int i = 0;
    while(x){
        nums[i] =  x % 10;
        i++;
        x /= 10;
    }
    int j = 0;
    for(; j < i; j++){
        if(nums[j] != nums[--i])
            return false;
    }
    return true;
}
```