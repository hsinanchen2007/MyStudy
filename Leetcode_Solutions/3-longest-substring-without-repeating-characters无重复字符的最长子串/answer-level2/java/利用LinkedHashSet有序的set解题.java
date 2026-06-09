### 解题思路
主要的思路是利用的set的LinkedHashSet 是有序的;
1)当碰到重复的字符时，保留之前没有遇到重复字符的maxCount
2)当第二次遇到重复字符时，判断本次set.size() 是否大于上次的maxCount
  maxCount = maxCount > set.size()?maxCount:set.size();
3)再返回时比较最后一次的set.size()与maxCount的大小;

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
            //创建一个有序set;
            Set<Character> set = new LinkedHashSet<>();
            //默认不重复最大的字符串长度为0;
            int maxCount = 0;
            for(int i = 0;i< s.length();i++){
                if(set.contains(s.charAt(i))){
                    maxCount = maxCount > set.size()?maxCount:set.size();
                    //利用有序的set删除没用的;
                    Iterator<Character> iterator = set.iterator();
                    while (iterator.hasNext()) {
                        Character c = iterator.next();
                        iterator.remove();
                        if(c.equals(s.charAt(i))) break;
                    }
                }
                set.add(s.charAt(i));
            }
            //最后确认是否set存的最后的是否 > set.size;
            return maxCount > set.size()?maxCount:set.size();
        }
}
```