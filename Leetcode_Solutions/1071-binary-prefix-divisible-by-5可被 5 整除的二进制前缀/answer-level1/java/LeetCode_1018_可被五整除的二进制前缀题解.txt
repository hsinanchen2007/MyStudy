### 解题思路
```
int tmp = 0

// let i to a.lenth

i = ((i << 1) | a[i]) % 10

// 0 || 5 true
// false
```

二进制的每一位（从低位向高位来看）都是之前那一位的2倍 + 当前值

每次都只关注个位数，所以每次都 % 10

如果是0 || 5 ， 就可以被5整除。

```
(a * b) % c = (a % c * b % c) % c
```

**二进制从高位往低位求十进制可以使用**

```
int[] A

int num = 0

// circle a.length

num = (num * 2 | A[i])
```

### 代码

```java
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> ans = new ArrayList<>();
        int num = 0;

        for (int i = 0; i < A.length; i++) {
            num = (num << 1 | A[i]) % 10;
            ans.add(num == 0 || num == 5);
        }
        return ans;
    }
}
```