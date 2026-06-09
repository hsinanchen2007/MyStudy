### 解题思路
将chars的字符用一个int数组表示出来，然后word每使用一个字符则将对应的
int[i]=1,从而达到表示已经使用了的目的，然后循环查询还有没有需要的字符没有被使用即可

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int result = 0;
        int[] charIndexs = new int[chars.length()];
        for (String item : words) {
            int itemLength = item.length();
            for (int i = 0; i < itemLength; i++) {
                char ch = item.charAt(i);
                int charIndex = chars.indexOf(ch);
                while (charIndex >= 0) {
                    if (charIndexs[charIndex] != 1) {
                        charIndexs[charIndex] = 1;
                        break;
                    }
                    charIndex = chars.indexOf(ch, charIndex + 1);
                    if (charIndex == -1) {
                        break;
                    }
                }
                if (charIndex == -1) {
                    break;
                }
                if (i + 1 == itemLength) {
                    System.out.println(item);
                    result += itemLength;
                }
            }
            charIndexs = new int[chars.length()];
        }
        return result;
    }
}
```