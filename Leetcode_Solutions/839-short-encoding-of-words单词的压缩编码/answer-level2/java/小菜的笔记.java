### 解题思路
此处撰写解题思路
对于字符串，遍历其所有子串，如果在集合中，就删除。一定要是集合，因为集合不会存储重复的字符串。

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> set=new HashSet(Arrays.asList(words));
        int sum=0;
        for(String word:words){
            for(int k=1;k<word.length();k++){
                set.remove(word.substring(k));
            }
        }
        for(String s:set){
            sum+=s.length()+1;
        }
        return sum;
    
       
    }
   
    
}
```