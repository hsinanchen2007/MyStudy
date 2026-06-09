### 解题思路
数学解法很厉害
https://leetcode-cn.com/problems/add-digits/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-5-7/

### 代码

```c
int addDigits(int num){
    return (num - 1) % 9 + 1;
}
```