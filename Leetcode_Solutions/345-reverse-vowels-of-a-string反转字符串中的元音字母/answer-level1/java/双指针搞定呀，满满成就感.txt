### 解题思路和注意点
因为涉及前后互换，所以自然想到双指针
操作双指针要用好while
while里面有index下标，操作的时候一定注意不要数组越界，加好判断

### 代码

```java
class Solution {
    static Set<Character> set = new HashSet<>();

    static {
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
    }

    public String reverseVowels(String s) {
        int begin = 0;
        int end = s.length() - 1;
        char[] chars = s.toCharArray();
        while (begin < end) {
            while ((begin < s.length()) && !set.contains(Character.toLowerCase(chars[begin]))) {
                begin++;
            }
            while ((end > 0) && !set.contains(Character.toLowerCase(chars[end]))) {
                end--;
            }
            if (begin >= end) {
                break;
            }
            Character tmp = chars[begin];
            chars[begin] = chars[end];
            chars[end] = tmp;
            begin++;
            end--;
        }
        return String.valueOf(chars);
    }
}
```