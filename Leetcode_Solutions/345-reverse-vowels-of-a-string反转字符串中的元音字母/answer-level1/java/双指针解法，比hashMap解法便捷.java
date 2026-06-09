### 解题思路
该问题用双指针解法最为便捷，其中两端的指针分别从0和s的length-1开始，每次分别去除两个字符，看我们当前的list是否包含元音字母，这样如果两者都包含，将该两者的位置互换。
注： 1. 可以新建一个空字符数组，来进行装填新的字符
     2. 对于边界可以看到，start和end存在相等的情况，一定要考虑
     3. 交换的时候，将空数组进行 i++和j--,其实就是个重新填充

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        List<Character> vowelList = new ArrayList<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        int start = 0;
        int end = s.length() - 1;
        char[] currentArray = new char[s.length()];
        while (start <= end) {
            char ci = s.charAt(start);
            char cj = s.charAt(end);

            if (!vowelList.contains(ci)) {
                currentArray[start++] = ci;
            } else if (!vowelList.contains(cj)) {
                currentArray[end--] = cj;
            } else {
                currentArray[start++] = cj;
                currentArray[end--] = ci;
            }
        }

        return new String(currentArray);
    }
}
```