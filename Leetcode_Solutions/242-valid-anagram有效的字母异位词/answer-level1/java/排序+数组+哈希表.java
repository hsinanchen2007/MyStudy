## 排序
```
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        char[] arrS = s.toCharArray();
        char[] arrT = t.toCharArray();
        Arrays.sort(arrS);
        Arrays.sort(arrT);
        for (int i = 0; i < s.length(); ++i) {
            if (arrS[i] != arrT[i]) return false;
        }
        return true;
    }
}
```
时间复杂度: O(nlogn)
空间复杂度: O(k)或O(n)，k为字符串长度，是否O(n)取决于排序算法
## 数组
```
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] map = new int[26];
        for (char i : s.toCharArray()) ++map[i - 'a'];
        for (char i : t.toCharArray()) --map[i - 'a'];
        for (int i : map) if (i != 0) return false;
        return true;
    }
}
```
时间复杂度：O(n)
空间复杂度: O(k)，k为字符串长度
## 哈希表
```
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        Map<Character, Integer> map = new HashMap<>();
        for (char i : s.toCharArray()) map.put(i, map.getOrDefault(i, 0) + 1);
        for (char i : t.toCharArray()) map.put(i, map.getOrDefault(i, 0) - 1);
        for (int i : map.keySet()) if (map.get(i) != 0) return false;
        return true;
    }
}
```
时间复杂度：O(n)
空间复杂度: O(k)，k为字符串长度
