这个题目有坑，坑在不是从0开始，而是从1开始。所以如果要用进制转换的思路来解决的话，在处理每一位的时候要把当前的位进行减1操作。
```
 public String convertToTitle(int n) {
        StringBuilder stringBuilder = new StringBuilder();
        while (n != 0) {
            n --;//这里稍作处理，因为它是从1开始
            stringBuilder.append((char)(n % 26 + 'A'));
            n /= 26;
        }
        return stringBuilder.reverse().toString();
    }
```
