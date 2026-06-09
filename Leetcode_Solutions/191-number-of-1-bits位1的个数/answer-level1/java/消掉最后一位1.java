
eg:
x	        1 1 0 0 0
x - 1	    1 0 1 1 1
x & (x - 1)	1 0 0 0 0
则 x 二进制的最后一位 1 被消掉；

```
public int hammingWeight(int n) {
    int count = 0;
    while (n != 0) {
        count ++;
        n = n & (n - 1);
    }
    return count;
}
```
