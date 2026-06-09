
原理就是：一位一位切割，简单粗暴。
可以优化的地方就在于官方题解中的「偏移表」的概念，确实比较难总结。
```
 public int strStr(String haystack, String needle) {
        //0. 判空； 1.不断地切割，然后用startWith判断即可
        if (haystack == null || needle == null) {
            return -1;
        }
        if (needle.length() == 0) {
            return 0;
        }
        //依次比对即可
        int length = haystack.length();
        for (int i = 0; i < length; i++) {
            if (haystack.startsWith(needle)) {
                //startWith，直接返回i
                return i;
            } else {
                if (haystack.length() == needle.length()) {
                    //长度相同，没必要继续切割，返回-1
                    return -1;
                } else {
                    //长度不同，所以haystack长度至少是2，可以继续切割
                    haystack = haystack.substring(1);
                }
            }
        }
        return -1;
    }
```
