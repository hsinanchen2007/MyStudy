### 解题思路
已知字符传就是IP，只需要遍历一次即可，虽然replace很香，但正则匹配是需要时间的

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        char[] charArr = address.toCharArray();
        char[] charDefangIpArr = new char[address.length() + 6];
        for (int i = 0, j = 0; i < charArr.length; i++) {
            int temp = i + j;
            if (charArr[i] != '.') {
                charDefangIpArr[temp] = charArr[i];
            } else {
                charDefangIpArr[temp] = '[';
                charDefangIpArr[temp + 1] = '.';
                charDefangIpArr[temp + 2] = ']';
                j += 2;
            }
        }
        return String.valueOf(charDefangIpArr);
    }
}
```