直接查找.的下标，然后再拼接，接着继续寻找下标.

![image.png](https://pic.leetcode-cn.com/1a186b42a384684a68cd074af422c8dd8a5d755bf8f04ee8ce622765e7a5e2e8-image.png)

```Java
class Solution {
    public String defangIPaddr(String address) {
        int formIndex = 0;

        StringBuilder sb = new StringBuilder();
        while(formIndex > -1) {
            int terminatorIndex = address.indexOf('.', formIndex);
            if (terminatorIndex > -1) {
                sb.append(address, formIndex, terminatorIndex).append("[.]");
                formIndex = terminatorIndex + 1;
            } else {
                sb.append(address, formIndex, address.length());
                break;
            }
        }
        return sb.toString();
    }
}
```