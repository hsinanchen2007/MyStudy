### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int repeatedStringMatch(String A, String B) {
            for (int i = 0; i < A.length(); i++) {
            if (A.charAt(i) == B.charAt(0)) {
                int k = i;
                int count = 1;//循环次数
                int j = 0;
                while (A.charAt(k) == B.charAt(j)) {
                    k++;
                    j++;
                    if (j >= B.length()) return count;
                    if (k >= A.length()) {
                        k = 0;
                        count++;
                    }
                }
            }
        }
        return -1;
    }
}
```