### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxArea(int[] a){
        int max = 0;
        for (int i = 0; i < a.length; i++) {
            for (int j = i + 1; j < a.length; j++) {
                int area = (j - i) * Math.min(a[i], a[j]);
                max = Math.max(max, area);
            }
        }
        return max;
    }
}
```