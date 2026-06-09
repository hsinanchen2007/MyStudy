### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<String> ret = new ArrayList<>();
    public List<String> restoreIpAddresses(String s) {
        int n = s.length();
        if(n < 4 && n > 12){
            return ret;
        }
        helper(s, 0, "", 0);
        return ret;
    }
    // p记录在字符串上游走的下标， already是已经划分好的字符串， cnt是已经有几段了
    private void helper(String s, int p, String already, int cnt){
        if(cnt == 4 && p == s.length()){
            ret.add(already);
            return;
        }
        // 已经四段了，p却还没到s的尾部
        // 或者p已经到尾端,却还没有四段
        if(cnt == 4 || p == s.length()){
            return;
        }
        for(int i = 1; i < 4; i++){
            if(p + i > s.length()){
                return;
            }
            String str = s.substring(p, p+i);
            if(isValid(str)){
                helper(s, p+i, already + str + (p+i == s.length() ? "" : "."), cnt+1);
            }
        }
        return;
    }
    private boolean isValid(String s){
        if(s.charAt(0) == '0'){
            return s.length() == 1;
        }
        return Integer.valueOf(s) <= 255;
    }
}
```