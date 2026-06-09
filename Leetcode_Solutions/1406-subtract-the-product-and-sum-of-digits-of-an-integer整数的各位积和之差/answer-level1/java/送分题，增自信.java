### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        String string = String.valueOf(n);
        long he = 0;
        long ji = 1;
        for (int i = 0; i < string.length(); i++) {
            int tmp = Integer.parseInt(String.valueOf(string.charAt(i)));
            he += tmp;
            ji *= tmp;
        }
        return (int) (ji - he);
    }
}
```