
```java
import java.util.HashSet;
import java.util.Set;
class Solution {
    /**
     * 依据hashSet不允许装重复元素的性质，采用滑动窗口的是思路，对传过来的字符串s进行遍历，
     * 如果set中未包含这个元素，就将这个元素扔进set中，并将i+1进入下次一遍历
     * 否则，就将这个元素从set中移除，并j+1进入下一次遍历，
     * 利用求最大值的函数，将i-j（即在这一次循环中不重复的最大长度）赋给旧的最大值
     * 当任何i，j有任何一方>字符串的长度
     * 就说明遍历结束，将此时的不重复最大长度return即可
     * @param s
     * @return
     */
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int maxLength = 0;
        int i=0 , j=0;
        while (i<s.length() && j<s.length()){
            if (!set.contains(s.charAt(i))){
                set.add(s.charAt(i));
                i++;
            }else {
                set.remove(s.charAt(j));
                j++;
            }
            maxLength = Math.max(maxLength,i-j);
        }
        return maxLength;

    }
}
```