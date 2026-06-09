### 解题思路

java滑动窗口法，比较好理解
substring要注意是否会超出string的长度

### 代码

```java
class Solution {
  public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        int[] arrayS1 = createLetterTime(s1);
        int windowLength = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            int len = (i + windowLength >= s2.length()) ? s2.length() - i : windowLength;
            //substring要注意是否会超出string的长度
            int[] arrayS2 = createLetterTime(s2.substring(i, i + len));
            if (isMatch(arrayS1, arrayS2)) {
                System.out.println("error is :" + s2.substring(i, i + windowLength));
                return true;
            }
        }
        return false;

    }

    public int[] createLetterTime(String str) {
        int[] array = new int[26];
        for (int i = 0; i < str.length(); i++) {
            array[str.charAt(i) - 'a']++;
        }
        return array;
    }

    public boolean isMatch(int[] arrayS1, int[] arrayS2) {
        for (int i = 0; i < 26; i++) {
            if (arrayS1[i] != arrayS2[i]) {
                return false;
            }
        }
        return true;
    }
}
```