维护一个滑动窗口，滑动窗口内所有字母的种类<=2。其中`l`是窗口的左边界，`r`是窗口的右边界，每次默认会将右窗口向右移动一格。可以发现，其实我们想要的结果`max = Math.max(max, 当前窗口大小)`。

现在的问题就是，如何保证滑动窗口中的字母种类不超过2？

这里我是利用了一个Map，其中key为字母，value为字母出现的频次。r指针再扫描区间的时候，会将每一个扫描的字母都加入map中。

当`map.size() > 2`的时候，说明map中包含了3个重复元素了，此时就要移动`l`指针了。每次移动`l`指针，都会将它对应的字母所在map中的频次-1，当频次为0时，说明这个字母在滑动窗口中就已经没了，因此此时的窗口就又是符合题意的了。

附上代码：
```java
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int res = 0;
        for(int l = 0, r = 0; r < s.length(); r++) {
            char c = s.charAt(r);
            if(!map.containsKey(c)) {
                map.put(c, 1);
            }else {
                map.put(c, map.get(c) + 1);
            }
            
            while(map.size() > 2) {
                char leftChar = s.charAt(l++);
                int value = map.get(leftChar) - 1;
                if(value == 0) {
                    map.remove(leftChar);
                }else {
                    map.put(leftChar, value);
                }
            }
            res = Math.max(res, r - l + 1);
        }        

        return res;
    }
}
```

同理，[340. 至多包含 K 个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/)这个hard题也是一样，只需要把这个代码copy过去，然后把while循环中的2改成k即可。。