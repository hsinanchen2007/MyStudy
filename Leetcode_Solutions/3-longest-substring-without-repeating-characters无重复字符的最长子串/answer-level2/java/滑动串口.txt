### 解题思路
所谓滑动窗口，就是窗口左右界根据不同情况变动，此题我们要求的就是在窗口内没有重复数字的最大窗口。

思路:左边界设为left=0，开始遍历字符串同时滑动右边界right，如何判断当前字符没有出现在前面的字符串       里呢？可以倒着遍历，即遍历s[left,right-1]，没有的话继续滑动，有的话左边界设为重复字符的右一位      start+1。重复以上直到遍历完字符串,时间复杂度O(N^2)。每次取结果
        res=Math.max(res,right-left+1)
优化:可以利用Map来存储字符和对应的位置，这样查找的复杂度为O(1)，并且直接获得了下一个起点的位置。
        left = map.get(c)+1 if map.contains(c);
     需要注意一点的是左边界left是一定向右滑动的，但会存在这种情况abcbcad,在判断第二a时会因为map里      存有a而导致left又滑回去，因此在改变窗口是需要加一个判断
        left = Math.max(left,map.get(c));
     时间复杂度O(N)

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> map = new HashMap<>();
        int res = 0;
        int start = 0;
        for(int i=0;i<s.length();++i){
            Integer k = map.get(s.charAt(i));
            if(k!=null){
                start = Math.max(k,start);
            }
            map.put(s.charAt(i),i+1);
            res = Math.max(i-start+1,res);
        } 
 
        return res;
    }
}
```