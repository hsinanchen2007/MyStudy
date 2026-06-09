### 解题思路
例如a="1100101",b="1011"
1、将a,b反转，ar="1010011",br="1101"
2、定义isCarry，代表是否需要进位
3、遍历max次（取a,b大的那个），并与isCarry比较，详细请看代码
4、将结果再次反转即可

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int aLength = a.length();
        int bLength = b.length();
        int max = Math.max(aLength, bLength);
        StringBuilder ar = new StringBuilder(a).reverse();
        StringBuilder br = new StringBuilder(b).reverse();
        //是否进位
        boolean isCarry = false;
        for (int i = 0; i < max; i++) {
            char aChar = i >= aLength ? '0' : ar.charAt(i);
            char bChar = i >= bLength ? '0' : br.charAt(i);
            if (aChar == '1' && bChar == '1') {
                sb.append(isCarry ? '1' : '0');
                isCarry = true;
            } else if (aChar == '0' && bChar == '0') {
                sb.append(isCarry ? '1' : '0');
                isCarry = false;
            } else {
                sb.append(isCarry ? '0' : '1');
            }
        }
        if (isCarry) sb.append("1");
        return sb.reverse().toString();
    }
}
```