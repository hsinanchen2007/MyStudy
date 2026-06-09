如果想要回文的话，必须只有一个字母的数量为奇数，如果多个字母为奇数就不可能是回文排列，使用哈希表来存储和判断。
```java
class Solution {
    public boolean canPermutePalindrome(String s) {
         int times=0;
        Map<Character,Integer>map=new HashMap<>();
        for(int i=0;i<s.length();i++)
        {
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
        }
        for(Character c:map.keySet())
        {
            int num=map.get(c);
            if(num%2!=0)
                times++;
            if(times>1)
                return false;
        }
        return true;
    }
   
}
```