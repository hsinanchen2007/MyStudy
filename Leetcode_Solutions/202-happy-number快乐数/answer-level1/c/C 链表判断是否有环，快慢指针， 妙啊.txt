![image.png](https://pic.leetcode-cn.com/f8c4efd1c68ef4e992894c7133c5ed521407f288a74223eeb7c9aa09ae0d21aa-image.png)

思路很简单，用快慢指针, 脑子太笨我没想到。。

```c
int get_next(int n) {
    int temp = 0;
    while(n) {
        temp += (n % 10) * (n % 10);
        n /= 10;
    }
    return temp;
}


bool isHappy(int n){
    int p = n, q = n;
    while(q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if(p == q) break;
    }
    return q == 1;
}
```
