### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int point_a =0;
        int point_b =0;
        int max =0;
        HashSet<Character> hash_set =new HashSet();
        while(point_b<s.length()){
            if(!hash_set.contains(s.charAt(point_b))){
                hash_set.add(s.charAt(point_b));
                point_b++;
                max = Math.max(hash_set.size(),max);
            }else{
                hash_set.remove(s.charAt(point_a));
                point_a++;
            }
            
        }
        return max;
    }
   
}
```