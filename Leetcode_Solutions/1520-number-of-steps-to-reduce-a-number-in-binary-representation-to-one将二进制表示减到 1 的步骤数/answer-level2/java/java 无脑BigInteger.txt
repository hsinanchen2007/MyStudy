### 思路
用BigInteger的话真的是无脑写就可以了。 (PS: 不过不推荐这么做哦。。 )
<br>

```java
    public int numSteps(String s) {
        BigInteger bi = new BigInteger(s, 2);
        int ans = 0;
        while (!bi.equals(BigInteger.ONE)) {
            if (bi.mod(BigInteger.TWO).equals(BigInteger.ZERO)) {
                // 偶数
                bi = bi.divide(BigInteger.TWO);
            } else {
                bi = bi.add(BigInteger.ONE);
            }
            ans++;
        }
        return ans;
    }
```