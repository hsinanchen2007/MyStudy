### 解题思路
小数转二进制 乘二取整，正向排列；
如果是0.1这种不能用二进制精确表示的值，这个过程会像无理数一样无穷尽……
### 代码

```java
class Solution {
    public String printBin(double num) {
        StringBuilder builder = new StringBuilder("0.");
        for (int count = 0; count <= 30; count++) {
            num = num * 2;
            if (num > 1) {
                builder.append(1);
                num -= 1;
            } else if (num == 1){
                builder.append(1);
                return builder.toString();
            } else {
                builder.append(0);
            }
        }
        return "ERROR";
    }
}
```