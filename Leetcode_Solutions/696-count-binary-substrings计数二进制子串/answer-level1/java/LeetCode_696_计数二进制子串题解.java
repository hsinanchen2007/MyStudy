### 解题思路

结果一：
- 记录重复子串的长度，之后比较其中较小的，与结果相加

结果二：
- 使用两个变量分别记录上一次重复子串的长度和当前重复子串的长度，如果上一次重复子串的长度 >= 当前重复子串的长度，说明符合条件，结果 + 1

### 代码

```java
class Solution {
    public int countBinarySubstringsNew(String s) {
        int cur = 0, pre = 0, ans = 0;
        for (int j = 1; j < s.length(); j++) {
            if (s.charAt(j) == s.charAt(j - 1)) ++cur;
            else {
                pre = cur;
                cur = 0;
            }
            if (pre >= cur) ++ans;
        }
        return ans;
    }

    public int countBinarySubstrings(String s) {
        List<Integer> flags = new ArrayList<>();
        int ans = 0;

        for (int i = 0; i < s.length();) {
            // 计算连续0的长度
            ans = 0;
            while (i < s.length() && '0' == s.charAt(i)) {
                ans ++;
                i++;
            }
            flags.add(ans);
            // 计算连续1的长度
            ans = 0;
            while (i < s.length() && '1' == s.charAt(i)) {
                ans ++;
                i++;
            }
            flags.add(ans);
        }


        int sum = 0;
        for (int i = 1; i < flags.size(); i++) {
            sum += Math.min(flags.get(i), flags.get(i - 1));
        }

        return sum;
    }
}
```