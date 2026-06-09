### 解题思路
遍历一遍，用prev记录每个char，cnt记录重复的个数（默认为1）。
从1位置开始遍历，如果和前一个相同则增加cnt，如果不同则变更stringbuilder的内容，更新prev以及cnt。
### 代码

```java
class Solution {
    public String compressString(String s) {
        if(s.length()<3) return s;
        StringBuilder sb = new StringBuilder();
        char prev = s.charAt(0);
        sb.append(prev);
        int cnt= 1;
        for(int i= 1; i<s.length();++i){
            if(s.charAt(i)==prev){
                 ++cnt;
            }else{
                sb.append(cnt);
                prev = s.charAt(i);
                sb.append(prev);
                cnt=1;
            }
            
        }
        sb.append(cnt);
        if(sb.length()<s.length()) return sb.toString();
        return s;    
    }
}
```