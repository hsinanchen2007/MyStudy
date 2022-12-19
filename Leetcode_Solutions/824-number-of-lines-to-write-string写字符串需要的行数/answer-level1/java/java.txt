### 解题思路
一行写不下换行

### 代码

```java
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int sum = 0;
        // 从第一行开始
        int[] result = new int[]{1, 0};
        for (int i = 0; i < S.length(); ++i) {
            if (sum + widths[S.charAt(i) - 97] > 100) {
                // 换行
                result[0]++;
                sum = widths[S.charAt(i) - 97];
            } else {
                sum += widths[S.charAt(i) - 97];
            }
        }
        result[1] = sum;
        
        return result;  
    }
}
```