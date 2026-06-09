### 沿着中线对称进行交换
```java []
class Solution {
    private void swap(char[] s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    
    public void reverseString(char[] s) {
        if (s == null) return;
        int n = s.length;
        for (int i = 0; i < n/2; i++) {
            swap(s, i, n-1-i);
        }
        
    }
}
```

PS:
交换可以使用位运算
* 异或满足交换律和结合律
* x ^ x == 0
* x ^ 0 == x

```java []
a = a^b;
b = a^b;
a = a^b;
```
位运算比较快（但是平时不要这么用，并不见得能够比朴素的交换来的更快。而且这种方法存在一个缺陷：如果 a 和 b 引用的是同一个变量的话，使用这种方法会使得这个变量变为0。）