### 解题思路
太多字符串操作，速度被消耗了。
![image.png](https://pic.leetcode-cn.com/d47d85635a8bac043b319435eee3cff4eb77216a4fa8bf70c4c66f802eea6355-image.png)

### 代码

```java
class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        String[] carr = new String[str1.length() + 1];
        carr[0] = "";
        for (int i = 1; i <= str1.length(); i++) {
            carr[i] = carr[i - 1] + str1.charAt(i - 1);
        }
        String[] tmp = new String[str1.length() + 1];
        for (int i = 1; i <= str2.length(); i++) {
            tmp[0] = carr[0] + str2.charAt(i - 1);

            for (int j = 1; j <= str1.length(); j++) {
                String t1 = carr[j].length() < tmp[j - 1].length() ?
                        carr[j] + str2.charAt(i - 1) : tmp[j - 1] + str1.charAt(j - 1);
                tmp[j] = t1;
                if (str1.charAt(j - 1) == str2.charAt(i - 1) && t1.length() > carr[j - 1].length() + 1) {
                    tmp[j] = carr[j - 1] + str1.charAt(j - 1);
                }
            }

            String[] arr = carr;
            carr = tmp;
            tmp = arr;
        }

        return carr[carr.length - 1];
    }
}
```