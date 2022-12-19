### 解题思路


### 代码
![捕获5.PNG](https://pic.leetcode-cn.com/07e2ff9c42b1109b607e4d6eb581cf7485b762c67029c854eea4001f6fa136b8-%E6%8D%95%E8%8E%B75.PNG)

```java
class Solution {
    public char firstUniqChar(String s) {
        /*if(s==null||s.length()==0){
            return ' ';
        }
        int[] target=new int[26];
        for(int i=0;i<s.length();i++){
            target[s.charAt(i)-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(target[s.charAt(i)-'a']==1){
                return s.charAt(i);
            }
        }
        return ' ';*/
        int len=s.length();
        if(s==null||len==0){
            return ' ';
        }
        char[] chs=s.toCharArray();
        HashMap<Character,Integer> map=new HashMap<>();
        for(int i=0;i<chs.length;i++){
            if(!map.containsKey(chs[i])){
                map.put(chs[i],1);
            }else{
                int cnt=map.get(chs[i]);
                map.put(chs[i],cnt+1);
            }
        }
        for(int i=0;i<chs.length;i++){
            if(map.get(chs[i])==1){
                return chs[i];
            }
        }
        return ' ';
    }
}
```