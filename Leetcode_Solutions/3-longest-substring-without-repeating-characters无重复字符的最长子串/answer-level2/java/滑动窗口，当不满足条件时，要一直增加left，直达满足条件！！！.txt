# 窗口内始终时满足条件的序列，连续
### 滑动窗口，当不满足条件时，要一直增加left，直达满足条件！！！
### 滑动窗口，当不满足条件时，要一直增加left，直达满足条件！！

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> count=new HashSet<>();
        int start =0,res=0;
        int length=s.length();
        for(int end=0;end<length;end++){
            char c=s.charAt(end);
            while(count.contains(c)){
                count.remove(s.charAt(start));
                start++;
            }
            res=Math.max(res,end-start+1);
            count.add(c);


        }
        return res;


    }
}
```