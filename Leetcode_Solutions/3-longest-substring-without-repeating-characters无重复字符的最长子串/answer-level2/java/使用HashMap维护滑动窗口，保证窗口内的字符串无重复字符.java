关键在于何时移动左端点、右端点：
1.当前遍历的字符不在窗口内，左端点不动。
2.反之，假设当前字符在窗口内的下标为i，那么左端点应该移动到i+1的位置，同时将当前字符的位置上重新覆盖。
3.左端点移动后，应对map进行一些更新，以"wobgrovw"为例，右端点移动到下标6时，移动左端点从0到下标2，此时也应该将map中0~1下标对应的字符记录删除。

```
Java代码
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] ss = s.toCharArray() ;
        int left = 0 , right = 0 , n = ss.length ;
        int max = Integer.MIN_VALUE ;
        HashMap<Character,Integer> map = new HashMap<>() ;
        while(right < n){
            if(map.containsKey(ss[right])){      //当前字符已在滑动窗口内
                max = Math.max(max,right - left) ;  //记录遍历至此最长的符合题意的字符串。right-left为当前窗口大小
                int temp = map.get(ss[right]) ;
                for(int i = left ; i <= temp ; i++){ 
                    map.remove(ss[i]) ;     // 清除部分map记录
                }
                left = temp + 1 ;   // 调整滑动窗口的左端点
            }
            map.put(ss[right],right) ;
            right++ ;
        }
        return Math.max(max,right - left) ;
    }
}
```
