![image.png](https://pic.leetcode-cn.com/fd20f4285e73a4ce8df72da13d26037499336005c2838869885d67362f5904d7-image.png)

```
public  boolean isLongPressedName(String name, String typed) {
            if (typed==null||name==null)
                return false;
            if (typed.length()<name.length())
                return false;
            int nameCharRepeate = 1;//name中某个字符重复的次数
            int typedCharRepeate =1 ;
            int j=0;
            int i=0;
            for (; i <name.length() ; ) {
                char c = name.charAt(i);
                if (j<typed.length() && c!=typed.charAt(j))
                    return false;
                while (++i<name.length() && name.charAt(i)==c) {
                    nameCharRepeate++;
                }
                if (j>=typed.length())
                    typedCharRepeate=0;
                while (++j<typed.length() && typed.charAt(j)==c) {
                    typedCharRepeate++;
                }
                if (typedCharRepeate<nameCharRepeate)
                    return false;
                nameCharRepeate = 1;
                typedCharRepeate =1 ;
            }
            if (i>=name.length()-1)
                return true;
            return false;

    }
```
