
### 思路：
滑动窗口：字符逐个进入队列，遇到队列中已有的字符时，队头指针移动到旧字符之后，将其出队，并继续进队（每次进队都更新最大长度）。

### 时间复杂度：
### O(n)
### 空间复杂度：
### O(n)

### 代码
```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        //建立存储字串字符和对应索引的map（注意map中key值不允许相等，本题不在此）
        Map<Character,Integer> strMap = new HashMap<Character,Integer>();
        //滑动窗口的左索引
        int left = 0;
        int max = 0;
        //若为空字串，返回0
        if(s == "") return 0;
        //滑动窗口开始
        for (int i = 0; i < s.length(); i++) {
            //若窗口中已经含有与待增加字符相同字符，则右划窗口删去旧字符
            if(strMap.containsKey(s.charAt(i)))
                left = Math.max(left,strMap.get(s.charAt(i)) + 1);
            //添加新字符
            strMap.put(s.charAt(i),i);
            //更新最大值
            max = Math.max(max,i - left + 1);
        }
        return max;      
    }

}
```
