### 解题思路

先计算出最大位移次数 也就是 shifts[0]到shifts[n]的和 sum
S[i] 需要位移的次数则是 sum - (shifts[0]到shifts[i-1]的和)
因为数值过大会溢出，所以在计算的时候每次都进行取余计算。

### 代码

```java
class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        char[] letters = new char[26];
        char[] newLetters = S.toCharArray();
        HashMap<Character, Integer> maps = new HashMap<>();
        for (int i = 0; i < letters.length; i++) {
            letters[i] = (char) (97 + i);
            maps.put(letters[i], i);
        }

        int maxShift = 0;
        for (int shift1 : shifts) {
            maxShift += shift1 % letters.length;
        }

        int shift = 0;
        for (int i = 0; i < newLetters.length; i++) {
            char c = newLetters[i];
            int index = maps.get(c);
            newLetters[i] = letters[(index + (maxShift - shift)) % letters.length];
            shift += shifts[i] % letters.length;
        }

        return String.valueOf(newLetters);
    }
}
```