```java
class Solution {
    public String reverseVowels(String s) {
        int begin = 0;
        int end = s.length() - 1;
        HashSet<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        char[] sArrays = s.toCharArray();
        // 使用双指针法
        while (begin < end) {
            if (vowels.contains(sArrays[begin]) && vowels.contains(sArrays[end])) {
                // 当左指针和右指针都是元音时，交换位置
                char temp = sArrays[begin];
                sArrays[begin++] = sArrays[end];
                sArrays[end--] = temp;
            } else if (vowels.contains(sArrays[begin]) && !vowels.contains(sArrays[end])) {
                // 当右指针不是元音时，右指针减一
                end--;
            } else if (!vowels.contains(sArrays[begin]) && vowels.contains(sArrays[end])) {
                // // 当左指针不是元音时，左指针加一
                begin++;
            } else {
                begin++;
                end--;
            }
        }


        return new String(sArrays);
    }
}
```