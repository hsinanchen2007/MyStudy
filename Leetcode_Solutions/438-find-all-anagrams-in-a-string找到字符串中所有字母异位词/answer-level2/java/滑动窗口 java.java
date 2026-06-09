### 解题思路
1. 通过双指针滑动窗口
2. 判断是否和p串长度相同
3. 再比较窗口串的字符出现频率和p串是否一致.

### 代码

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        if (s.length() == 0 || p.length() == 0 || p.length() > s.length()) return result;

        int[] pFreq = new int[26]; // pFreq 为p对应每个字符的频率数组
        int[] sFreq = new int[26]; // sFreq 为s滑动窗口对应每个字符的频率数组

        for (int i = 0; i < p.length(); i++) {
            pFreq[p.charAt(i) - 'a']++; 
        }

        int l = 0, r = -1; // 滑动窗口为chars[l,r]
        while (r + 1 < s.length()) {
            
            // 滑动窗口,控制窗口长度
            sFreq[s.charAt(++r) - 'a']++;
            if (r - l + 1 > p.length())
                sFreq[s.charAt(l++) - 'a']--;

            // 窗口和p串长度相等,比较两个数组
            if (r - l + 1 == p.length() && isSame(sFreq, pFreq))
                result.add(l);
        }

        return result;
    }

    public boolean isSame(int[] arr1, int[] arr2) {
        for (int i = 0; i < arr1.length; i++)
            if (arr1[i] != arr2[i]) return false;
        return true;
    }
}
```