### 解题思路
执行用时 : 0 ms, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
bool isPowerOfTwo(int n){
    if(n <= 0){
        return false;
    }else if(n == 1){
        return true;
    }else{
        return (n&(n - 1)) == 0 ? true : false;
    }
}
```