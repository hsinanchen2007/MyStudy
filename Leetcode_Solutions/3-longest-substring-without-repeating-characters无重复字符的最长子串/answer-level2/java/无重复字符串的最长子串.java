```java
import java.lang.Math;
import jav.util.*;
class Solution {
    /*暴力解法
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n == 0) return 0;
        char[] a = s.toCharArray();
        int max = 1;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                //判断i-j子串是否重复
                if(helper(a, i, j)){//不重复
                    max = (j-i+1) > max ? j-i+1 : max;
                }
            }
        }
        return max;
    }

    public boolean helper(char[] a, int left, int right){
        HashSet<Character> hs = new HashSet<>();
        for(int i = left; i<=right; i++ ){
            if(!hs.contains(a[i])){
                hs.add(a[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
    */
    /* 
    //滑动窗口法，i~j是最长无重复子串的滑动窗口，s[j]重复时，i+1
    //时间复杂度 O(n)
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n == 0 ) return 0;
        Set<Character> hs = new HashSet<>();
        int max = 1, i = 0, j = 0;
        while(i<n && j< n){
            if(hs.contains(s.charAt(j))){
                hs.remove(s.charAt(i++));
            }else{
                hs.add(s.charAt(j));
                max = (j-i+1) > max ? j-i+1 : max;
                j++;
            }
        }
        return max;
    }
    */
    //改进滑动窗口，当发现s[j]重复时，i不再+1，而是从子串i-j中找到与s[j]重复的坐标 j`， i = j` + 1
    //这需要map，key为s[j]，value为坐标
    //时间复杂度O(n)
    //可以改进，把map替换为长度为128的数组，存128个ascii码
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n == 0 ) return 0;
        Map<Character, Integer> map = new HashMap<>();
        int max = 1, i = 0, j = 0;
        while(i<n && j<n){
            if(map.containsKey(s.charAt(j))){
                i = Math.max(i, map.get(s.charAt(j))+1);
            }
            map.put(s.charAt(j), j);
            max = Math.max(max, j-i+1);
            j++;
        }
        return max;
    }
}
```