### 解题思路
set直接去重即可。不过感觉如果用字典树应该更节省内存？
### 代码

```java
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> seen = new HashSet<String>();
        Set<String> re = new HashSet<String>();

        for(int i = 0;i<=s.length()-10;i++){
            if(seen.contains(s.substring(i,i+10))){
                re.add(s.substring(i,i+10));
            }else{
                seen.add(s.substring(i,i+10));
            }

        }
        List<String> l = new ArrayList<>();
        for(String r:re){
            l.add(r);
        }
        return l;
    }
}
```