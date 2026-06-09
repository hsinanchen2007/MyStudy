### 解题思路
XOR 可以实现无进位的加法；
AND 可以求出进位；

### 代码

```c
int add(int a, int b){
    unsigned int ans = a^b;
    unsigned int up = a&b;
    while(up){
        unsigned tmp = up<<1;
        up = (up<<1)&ans;
        ans ^= tmp;
    }
    return ans;
}
```