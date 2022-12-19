在 Java 中,String#indexOf 方法的简化，源码基本没动，只是简单修改了一下形参列表
```
public class Demo028 {
    public static int strStr(String haystack, String needle) {
        return indexOf(haystack.toCharArray(), haystack.length(), needle.toCharArray(), needle.length());
    }

    public static int indexOf(char[] source, int sourceCount,
                       char[] target, int targetCount) {
        if (0 >= sourceCount) {
            return (targetCount == 0 ? sourceCount : -1);
        }

        if (targetCount == 0) {
            return 0;
        }

        char first = target[0];
        int max = sourceCount - targetCount;

        for (int i = 0; i <= max; i++) {
           //寻找第一个字符
            if (source[i] != first) {
                while (++i <= max && source[i] != first) ;
            }

            /*若已经找到了第一个字符，则比对剩下的字符 */
            if (i <= max) {
                int j = i + 1;
                int end = j + targetCount - 1;
                for (int k = 1; j < end && source[j]
                        == target[k]; j++, k++)
                    ;

                if (j == end) {
                    //找打了要陪陪的字符串
                    return i ;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(strStr("hello", "ll"));
    }
}
```
