**思路**
1.判断字符串是否只由空格组成，如果是，返回0
2.如果不是，将字符串拆成字符串数组。返回数组最后一个元素的长度
```
public class LengthOfLastWord {
    public int lengthOfLastWord(String s) {
        if (isBlank(s)) {
            return 0;
        }
        String[] ansStr = s.split(" ");
        return ansStr[ansStr.length - 1].length();
    }

    private boolean isBlank(String s) {
        if (s != null && s.length() != 0) {
            char[] chars = s.toCharArray();
            for (char temp : chars) {
                if (temp != ' ') {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}
```
