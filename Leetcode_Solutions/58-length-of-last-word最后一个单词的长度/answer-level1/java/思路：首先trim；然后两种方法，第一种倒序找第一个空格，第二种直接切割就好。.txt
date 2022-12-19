方法1:
```
 public int lengthOfLastWord(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        String trim = s.trim();
        int length = trim.length();
        //trim过后，beginIndex默认为最后一位，只需要找第一个出现的空格即可
        for (int i = length - 2; i >= 0; i--) {
            if (trim.charAt(i) == ' ') {
                return length - 1 - i;
            }

        }
        return length; 
    }
```

方法2: 相对更简洁一些
```
public int lengthOfLastWord(String s) {
       if (s == null || s.length() == 0) {
            return 0;
        }
        //先trim
        String trim = s.trim();
        //再切割
        String[] split = trim.split(" ");
        return split[split.length - 1].length();
    }
```

