### 解题思路
O(N)时间复杂度。

### 代码

```java
class Solution {
    public String compressString(String S) {
        if (S == null || S.length() <= 1) {
            return S;
        }
        
        int length = S.length();
        String results = "";
        int i = 0;
        while (i < length) {
            if (i == length - 1) {
                results += String.valueOf(S.charAt(i)) + 1;
                break;
            }

            char c = S.charAt(i);
            int j = i + 1;
            int count = 1;
            while (j < length && S.charAt(j) == c) {
                j++;
                count++;
            }
            results += String.valueOf(c) + count;
            
            if (j == length) {
                break;
            }
            i = j; 
        }

        if (results.length() >= length) {
            return S;
        }

        return results;
    }
}
```