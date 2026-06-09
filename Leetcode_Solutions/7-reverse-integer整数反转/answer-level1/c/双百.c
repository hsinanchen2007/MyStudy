### 解题思路
主要考虑溢出的处理
![image.png](https://pic.leetcode-cn.com/0f591063e33362e1f1b8f343858f536dda6f0cd3baa345efd17b523ac08621ff-image.png)
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
```