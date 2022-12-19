### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        //两个哈希表组合解题
        Set<String> set=new HashSet<>();
        Set<String> help=new HashSet<>();
        for(int i=0;i<=s.length()-10;i++){
            String cur=s.substring(i,i+10);
            if(!set.add(cur))
                help.add(cur);
        }
        return new ArrayList<String>(help); //将哈希集合中的元素转换为列表
    }
}
```