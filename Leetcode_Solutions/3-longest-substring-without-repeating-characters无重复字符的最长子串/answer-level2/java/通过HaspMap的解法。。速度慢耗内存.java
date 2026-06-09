### 解题思路
此处撰写解题思路
诶，我还是菜，得多锻炼。这个题目首先想到的办法是借助于HashMap。运行速度只超过5.%，内存超过6%。。哈哈哈哈哈，慢慢来吧。现在需要开阔思路，能把题目先解决出来。
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int resultLength = 0;       //最后的结果        
        HashMap<Character,Integer> map =new HashMap();  //将当前的字符存入map中，如果存在，则计算map的大小，即此次子串的长度。与当前的resultLength比较。
        if(s.length()==1) return 1;
        for(int i = 0; i < s.length();i++){
            if(!map.containsKey(s.charAt(i))){  //当前字符不是map的key，将该字符作为key，当前i作为value放入
                map.put(s.charAt(i),i);
            }else{
                /**
                    当前的字符已经作为key存入map了，则表示子串不能再加字符，得到长度，将i的值退回
                    到该子串的第二个字符的未知，清除map给下一次使用。（这里也就是我的解法速度慢，                     耗内存的原因了。。。。哈哈哈）
                **/
                resultLength = Math.max(resultLength,map.size());
                i = i-map.size();
                map.clear();
                
            } 
        }
        resultLength = Math.max(resultLength,map.size());
        return resultLength;
    }
}
```