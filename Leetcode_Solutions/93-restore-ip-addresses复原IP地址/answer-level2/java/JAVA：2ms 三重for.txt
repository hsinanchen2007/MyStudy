### 解题思路
此处撰写解题思路
算法思想就是在i，j，k三个地方后面插'.',并且判断被点分割的4个部分是否超出255
### 代码

```java

class Solution {
    List<String> result = new ArrayList<>();
    //算法思想就是在i，j，k三个地方后面插'.',并且判断被点分割的4个部分是否超出255
    public List<String> restoreIpAddresses(String s) {
        if (s.length() < 4 || s.length() > 12) return result;
        for (int i = 0; i <= 2 && i <= s.length() - 4; i++) {
            for (int j = i + 1; j <= 3 + i && j <= s.length() - 3; j++) {
                for (int k = j + 1; k <= k + 3 && k <= s.length() - 2; k++) {
                    if (k < s.length() - 4) continue;
                    if (f(0, i, s) && f(i + 1, j, s) && f(j + 1, k, s) && f(k + 1, s.length() - 1, s)) {
                        StringBuilder p = new StringBuilder(s);
                        p.insert(k + 1, '.');
                        p.insert(j + 1, '.');
                        p.insert(i + 1, '.');
                        result.add(p.toString());
                    }
                }
            }
        }
        return result;
    }

    //判断范围以及判断0的函数
    public boolean f(int start, int end, String s) {
        int res = 0;
        if (s.charAt(start) == '0' && start != end) return false;
        for (int i = start; i <= end; i++) {
            res = res * 10 + (s.charAt(i) - '0');
        }
        return res <= 255;
    }
}
```