### 解题思路
刚开始就想到用map，可以使用key-value,不断的更新value,保证key不变，后来不知道如何区分连续不断这个概念，纠结了好久，最后就想到这个点可以不用太认真，只要找出重复字符的位置，以及之间的距离,这样就可以找到最大连续字符数量；
后来才知道这是滑动窗口算法，看了网上的各种介绍后，还是懵逼，
哪位大神有对滑动窗口算法更好的帖子或者心得，请分享一下，不胜感激！

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int resultCount = 0 ;
        if (s.length()>0) {
            String[] aimArray = s.split("");
            int record = 0;
            Map<String,Integer> map = new HashMap<>();
            for (int i = 0; i <aimArray.length; i++) {
                if (map.size()>0 &&  map.containsKey(aimArray[i])) {

                    record = Math.max(record,map.get(aimArray[i]));
                }
                resultCount = Math.max(resultCount,i-record+1);

                map.put(aimArray[i],i+1);
            }
          
        } 
        return resultCount;
    }
}
```