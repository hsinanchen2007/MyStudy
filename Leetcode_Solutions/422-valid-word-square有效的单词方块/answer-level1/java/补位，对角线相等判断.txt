### 解题思路
![屏幕快照 2020-02-10 21.53.04.png](https://pic.leetcode-cn.com/3f2bdd11dd57369c9a7260c0d9bf56f3fb2bfd75a04e9bc15cce072cc9faa02e-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-10%2021.53.04.png)


### 代码

```java
class Solution {
    // 先进行补位，然后直接用对角线相等进行判断即可
    public boolean validWordSquare(List<String> words) {
        int m = words.size();
        if (m == 0) {
            return true;
        }
        int n = words.get(0).length();
        if (m != n) {
            return false;
        }
        for (int i = 0; i < m; i++) {
            if (words.get(i).length() > m) {
                return false;
            }
            StringBuilder append = new StringBuilder();
            for (int j = 0; j < m - words.get(i).length(); j++) {
                append.append("0");
            }
            words.set(i, words.get(i) + append.toString());
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (words.get(i).charAt(j) != words.get(j).charAt(i)) {
                    return false;
                }
            }
        }
        return true;
    }
}
```