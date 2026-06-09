### 解题思路
在历史做题遇到通过map来判断历史重复值的方法，因为在提交测试中遇到过一些bug,添加了一些感觉可以优化的代码。感觉自己借用之前的解题方法耍些小聪明，非暴力提交。没想到提交后还是在垫底。大佬云集哇，好了去看题解了。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<String,Integer> map = new HashMap();
        int maxLen = 0;
        int len = 0;
        for(int i = 0 ; i < s.length() ;  i++){
            String str = s.substring(i , i+1);
            if(map.containsKey(str)){
                if(maxLen < len){
                    maxLen = len;
                }
                len = 0;
                i = map.get(str);
                map.clear();
            }else{
                map.put(str , i);
                len++;
            }
        }
        if(maxLen < len){
            maxLen = len;
        }
        return  maxLen;
    }
}
```