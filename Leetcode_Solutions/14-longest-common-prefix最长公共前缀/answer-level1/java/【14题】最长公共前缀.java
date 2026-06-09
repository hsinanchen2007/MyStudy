**方法一：从后往前水平扫描**
/**
思路：
(1) 取数组中一个字符串作为匹配串去循环匹配数组中其它字符串。
(2) 发生不匹配就截去匹配串最后一个字符继续循环，匹配完成就匹配下一个字符串，直到最后。
(3) 如果匹配串在匹配过程中长度被截为0，则直接返回不匹配。
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        String prefix = strs[0];
        // 字符串可以被自身匹配，所以从第二个开始匹配。
        for (int i = 1; i < strs.length; i++) {
            // 如果匹配串不在要匹配字符串的开头，则表示不是要匹配字符串的前缀。
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) {
                    return "";
                }
            }
        }        
        return prefix;
    }
}
```

**方法二：从前往后水平扫描**
思路：
(1) 取数组中一个字符串从前往后遍历字符去匹配其它字符串的相同位置字符。
(2) 直到遍历超出数组中最短字符串长度或者遍历到的字符匹配不上，则返回当前匹配串。
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        for (int i = 0; i < strs[0].length() ; i++) {
            // 取出当前位置要匹配的字符。
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j ++) {
                if (i == strs[j].length() || strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
        }
        // 数组中其它字符串都能被 strs[0] 匹配。
        return strs[0];
    }
}
```

**方法三：分治算法**
思路：
将原数组拆分成每两个为一组，分别匹配最长公共前缀，将匹配结果继续两两匹配。
分治算法的基本思想：
(1) 将一个规模为N的问题分解为 K 个规模较小的子问题。
(2) 这些子问题相互独立且与原问题性质相同。
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        return longestCommonPrefix(strs,0,strs.length-1);
    }

    private String longestCommonPrefix(String[] strs,int l,int r) {
        if (l == r) {
            return strs[l];
        } else {
            // 将数组分成两组分别查找最长公共前缀，然后再查找两个公共前缀的最长公共前缀。
            int mid = (l + r)/2;
            String lcpLeft = longestCommonPrefix(strs,l,mid);
            String lcpRight = longestCommonPrefix(strs,mid+1,r);
            return commonPrefix(lcpLeft,lcpRight);
        }
    }

    private String commonPrefix(String left,String right) {
        // 找出两个字符串中教短的从前往后遍历，匹配出俩字符串最长公共前缀。
        int min = Math.min(left.length(),right.length());
        for (int i = 0; i < min; i++) {
            if (left.charAt(i) != right.charAt(i)) {
                return left.substring(0,i);
            }
        }
        return left.substring(0,min);
    }
}
```

**方法四：二分法查找**
思路：
(1) 得到字符串数组中最短字符串长度。
(2) 根据二分法查找遍历数组找到最长公共前缀。
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";
        int minLen = Integer.MAX_VALUE;
        // 遍历得到数组中最短字符串的长度。
        for (String str : strs){
            minLen = Math.min(minLen, str.length());
        }
        int low = 1;
        int high = minLen;
        // 用二分法从最短字符串中间循环遍历。
        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs,middle)){
                low = middle + 1;
            } else{
                high = middle - 1;
            }
        }
        return strs[0].substring(0,(low+high)/2);
    }

    private boolean isCommonPrefix(String[] strs,int len){
        // 截取当前位置之前的字符串判断是否是数组中字符串的公共前缀。
        String str1 = strs[0].substring(0,len);
        for (int i = 1; i < strs.length; i++){
            if (!strs[i].startsWith(str1)){
                return false;
            }
        }
        return true;
    }
}
```
