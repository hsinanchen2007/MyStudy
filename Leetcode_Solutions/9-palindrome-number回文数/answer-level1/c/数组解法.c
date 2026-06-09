### 解题思路
此处撰写解题思路
解法思路是将整数的数码分别存在int num[32]的数组内（int 型最大值为2,147,483,648够用）；
再比较首尾是否相等
### 代码

```c
bool isPalindrome(int x){
    int num[32] = { 0 };
    int r = 0, k = 0;
    if(x < 0) return false;
    
    while(x){
        r = x % 10;
        num[k++] = r;
        x /= 10;
    }

    for(int i = 0, j = k - 1; i < j; i++, j--){
        if(num[i] != num[j]){
            return false;
        }
    }
    return true;
}
```