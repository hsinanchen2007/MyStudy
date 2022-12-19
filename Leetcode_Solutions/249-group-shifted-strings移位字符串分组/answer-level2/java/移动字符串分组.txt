### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private String getKey(String s){
        StringBuilder sb=new StringBuilder();
        sb.append('a');
        int sub=s.charAt(0)-'a';
        for(int i=1;i<s.length();i++)
        {
            char ch=(char)(s.charAt(i)-sub);
            if(ch<'a')
                ch+=26;
            sb.append(ch);
        }
        return sb.toString();
    }
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> map=new HashMap<>();
        for(String s:strings)
        {
            String key=getKey(s);
            if(map.containsKey(key))
                map.get(key).add(s);
            else
            {
                map.put(key,new ArrayList<>());
                map.get(key).add(s);
            }
        }
        return new ArrayList<>(map.values());
    }
}
```