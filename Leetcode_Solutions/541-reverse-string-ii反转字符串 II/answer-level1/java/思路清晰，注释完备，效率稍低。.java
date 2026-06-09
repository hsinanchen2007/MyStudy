### 解题思路
执行用时 :2 ms, 在所有 Java 提交中击败了41.17%的用户

注意边界和特殊情况，题目本身不难。

### 代码

```java
class Solution {
    public String reverseStr(String s, int k) {
        // 1.判断非法情况
        if (s == null || s.length() == 0) {
            return s;
        }
        // 2.判断特殊情况
        if (s.length() <= 2 * k) {
            if (s.length() <= k) {
                return new StringBuffer(s).reverse().toString();
            } else {
                String frontK = new StringBuffer(s.substring(0, k)).reverse().toString();
                String lastK = s.substring(k);
                return frontK + lastK;
            }
        }

        int index = 0;
        StringBuffer result = new StringBuffer();
        // 3.循环不断交换，注意while结束条件
        while (index + 2 * k < s.length()) {
            result.append(new StringBuffer(s.substring(index, index + k)).reverse());
            result.append(new StringBuffer(s.substring(index + k, index + 2 * k)));
            index += 2 * k;
        }
        int last = s.length() % (2 * k);
        // 4.循环结束还有可能后面有要处理的字符串，这里注意
        if (last != 0) {
            int begin = (s.length() / (2 * k)) * (2 * k);
            String lastString = s.substring(begin);
            // a.剩余的字符串小于等于K个，全部翻转加在result后面即可。
            if (lastString.length() <= k) {
                result.append(new StringBuffer(lastString).reverse());
            } else {
                //b.剩余的字符串大于k，小于2k，前K个翻转，后面剩余的保持不翻转。
                String fontK = new StringBuffer(lastString.substring(0, k)).reverse().toString();
                String lastK = lastString.substring(k);
                result.append(fontK + lastK);
            }
        }
        return result.toString();
    }
}
```