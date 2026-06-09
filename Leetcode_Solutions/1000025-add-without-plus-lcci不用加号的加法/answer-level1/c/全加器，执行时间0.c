### 解题思路
全加器,
本位 = a XOR b XOR c
进位 = (a AND b) OR (c AND (a OR b))

### 代码

```c
int add(int a, int b) {
    unsigned int ans = 0,c = 0,mask = 1;
    while(mask){
        int ai = a&mask;
        int bi = b&mask;
        ans |= (ai^bi^c);
        c = (ai&bi)|(c&(ai|bi));
        c<<=1;
        mask<<=1;
    }
    return (int)ans;
}
```