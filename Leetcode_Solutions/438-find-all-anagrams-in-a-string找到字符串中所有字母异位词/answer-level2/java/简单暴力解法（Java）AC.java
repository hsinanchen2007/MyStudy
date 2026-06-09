![image.png](https://pic.leetcode-cn.com/86cbe5ea7bd0b01ecada4e038edadb736661d32fe2fd8e03613faa7dcb48b7d7-image.png)

### 解题思路
    直接暴力破解，因为排序所以，时间复杂度是O(n^2)

### 代码

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
            List<Integer> result = new ArrayList<>();
            char[] sChars = s.toCharArray();
            char[] pChars = p.toCharArray();
            Arrays.sort(pChars);
            String pp = String.valueOf(pChars);
            int lastIndex = sChars.length - pChars.length;
            for (int i = 0; i <= lastIndex; i++) {
                System.arraycopy(sChars,i,pChars,0,pChars.length);
                Arrays.sort(pChars);
                if (pp.equals(String.valueOf(pChars))) {
                    result.add(i);
                }
            }
            return result;
    }
}
```