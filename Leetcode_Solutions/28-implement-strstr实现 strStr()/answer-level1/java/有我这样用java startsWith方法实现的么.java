```
class Solution {
    public int strStr(String haystack, String needle) {

        if (needle.isEmpty()) {
            return 0;
        }
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.charAt(i) == needle.charAt(0)) {
                String a = haystack.substring(i);
                if (a.startsWith(needle)) {
                    return i;
                }
            }
        
        }
        return -1;
    }
}
```

虽然能实现，但是速度方面不是很理想，但是实际上这里也只是在subString的时候创建了一个对象吧，为什么速度就慢了那么多，求指点，这题
都没看到太多java的解法