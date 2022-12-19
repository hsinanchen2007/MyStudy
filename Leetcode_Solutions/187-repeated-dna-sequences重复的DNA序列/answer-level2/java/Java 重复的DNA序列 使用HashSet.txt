### 解题思路
从头开始遍历字符串，每次截取长度为10的字符串p，分为以下几种情况：
1.set集合不存在p,将p存入set中
2.set集合中存在p，那么p至少出现两次，是符合题目要求的字符串
    2.1 p符合要求，结果ans中无p，将p添加到ans里
    2.2 p符合要求，结果ans中有p，continue（如字符串 s = 'AAAAAAAAAAA' ，需要避免10个'A'重复添加至结果集）

### 代码

```java
class Solution {
    List<String> ans = new ArrayList<>() ;
    HashSet<String> set = new HashSet<>() ;
    public List<String> findRepeatedDnaSequences(String s) {
        if(s == null) return ans ;
        int len = s.length() ;
        if(len <= 10) return ans ;
        for(int i = 0 ; i + 10 <= len ; i++){
            String temp = s.substring(i,i+10) ;
            if(set.add(temp)){
               continue ; 
            }else if(!ans.contains(temp)){
                ans.add(temp) ;
            }
        }
        return ans ;
    }
}
```