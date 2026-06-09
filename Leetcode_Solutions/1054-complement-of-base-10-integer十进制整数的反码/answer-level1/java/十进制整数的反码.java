### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int bitwiseComplement(int N) {
        String s=Integer.toBinaryString(N);
        int a=s.length();
        int b=(int)Math.pow(2,a)-1;
        return b^N;
    }
}
```