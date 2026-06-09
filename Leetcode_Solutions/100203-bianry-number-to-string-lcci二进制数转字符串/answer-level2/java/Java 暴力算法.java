### 解题思路
没什么好说的

### 代码

```java
class Solution {
    public String printBin(double num) {
        StringBuilder sb = new StringBuilder("0.");
        for (int i = 1; i < 31 && num > 0; i++) {
            if (num >= Math.pow(0.5, i)) {
                num -= Math.pow(0.5, i);
                sb.append(1);
            } else sb.append(0);
        }
        return num == 0 ? sb.toString() : "ERROR";
    }
}
```