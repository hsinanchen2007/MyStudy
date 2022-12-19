### 解题思路
遍历字符串，如果下一个字符与上一个字符相等，就将该字符数量的+1。
否则，将上一个字符的数量拼接上去。
注意循环结束后，还需要将最后一个字符的数量加上去，因为循环体里操作的count永远是上一个字符的。

### 代码

```java
class Solution {
    public String compressString(String source) {
        if (source.length() == 0) {
            return source;
        }
        String result = String.valueOf(source.charAt(0));
        char ch = source.charAt(0);
        int count = 1;
        for (int i = 1; i < source.length(); i++) {
            if (source.charAt(i) == source.charAt(i - 1)) {
                count++;
            } else {
                result += String.valueOf(count) + String.valueOf(source.charAt(i));
                count = 1;
            }
        }
        //最后结束的时候，需要将最后的count拼接上去
        result += count;
        return result.length() >= source.length() ? source : result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = solution.compressString("aabcccccaa");
        System.out.println(s);
    }
}

```