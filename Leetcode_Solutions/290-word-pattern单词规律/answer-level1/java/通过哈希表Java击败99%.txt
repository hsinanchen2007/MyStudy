### 解题思路

通过HashMap记录字母对应的单词，如果单词不对应或者一个单词对应多个字母都返回false

![image.png](https://pic.leetcode-cn.com/3c1c876ac78110c465adafb17944ac6483da8f1803a384d22fd83077635ad7ef-image.png)

### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strArr = str.split(" ");
        if (pattern.length() != strArr.length) {
            return false;
        }
        Map<Character, String> map = new HashMap<>(26);
        for (int i = 0; i < strArr.length; i++) {
            if (map.get(pattern.charAt(i)) == null) {
                if (map.containsValue(strArr[i])) {
                    return false;
                }
                map.put(pattern.charAt(i), strArr[i]);
            }
            map.putIfAbsent(pattern.charAt(i), strArr[i]);
            if (!map.get(pattern.charAt(i)).equals(strArr[i])) {
                return false;
            }
        }
        return true;
    }
}
```