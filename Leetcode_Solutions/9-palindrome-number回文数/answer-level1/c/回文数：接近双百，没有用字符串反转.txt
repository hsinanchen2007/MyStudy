### 解题思路
刚好可以利用整数反转那到题
![image.png](https://pic.leetcode-cn.com/202aa6de109b64ad1361632d51c5daa5edd7554224792405287cd4d4d265136e-image.png)
### 代码

```c
int reverse(int x){
    long res = 0;
    while(x) {
         res = res * 10 + x % 10;
         x /= 10;
     }
     if(res != (int)res) return 0;
     return res;
}
bool isPalindrome(int x){
    if(x<0) return false;
    if(x==reverse(x)) return true;
    return false;
}
```