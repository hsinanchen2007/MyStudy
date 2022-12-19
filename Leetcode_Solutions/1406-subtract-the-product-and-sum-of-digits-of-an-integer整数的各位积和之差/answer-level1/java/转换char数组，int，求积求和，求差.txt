### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int sum = 0;
        int mul = 1;
        char[] chars = String.valueOf(n).toCharArray();
        for (char ch : chars) {
            int a = Character.getNumericValue(ch);
            sum += a;
            mul *= a;
        }
        return mul - sum;
    }
}
```