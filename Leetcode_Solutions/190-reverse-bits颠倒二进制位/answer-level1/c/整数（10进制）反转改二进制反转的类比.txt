### 解题思路
这题和整数反转的核心思想是一致的，只不过一个10进制一个2进制，所以触类旁通，把整数反转中关于10进制的特征换成2进制的特征。

### 代码

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t count=0;
    int i;
    for(i=0;i<32;i++){
        count=count*2+n%2;
        n=n/2;
    }
    return count;
}
```