### 解析
当字符串数组长度为 0 时则公共前缀为空，当字符串数组长度为1时，则公共前缀为strs[0]。可直接求出结果。
令最长公共前缀 为res，并进行初始化为第一个字符串。
遍历后面的字符串，依次将其与 为res 进行比较，两两找出公共前缀，最终结果即为最长公共前缀。
如果查找过程中出现了res为空或者strs[i]为空的情况，则公共前缀为空串，直接返回。
时间复杂度：O(n)。
### 代码
```java
public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        if (strs.length == 1) {
            return strs[0];
        }
        String res = strs[0];
        for (int i = 1; i < strs.length; i++) {
            String str = strs[i];
            if (str.equals("") || res.equals("")) {
                return "";
            }
            int start = 0;
            while (start < res.length() && start < str.length() && str.charAt(start) == res.charAt(start)) {
                start++;
            }
            res = res.substring(0, start);
        }
        return res;
    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)