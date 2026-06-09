### 解题思路


### 代码

```java
class Solution {
    public boolean canConstruct(String s, int k) {
         if (s.length()<k) return false;
         Map<Character,Integer> map=new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            map.put(c,map.getOrDefault(c,0)+1);
        }
        int single=0;
        for (Map.Entry<Character,Integer> res:map.entrySet())
        {
            if (res.getValue()%2==1) single++;
        }
        return single<=k?true:false;
    }
}
```