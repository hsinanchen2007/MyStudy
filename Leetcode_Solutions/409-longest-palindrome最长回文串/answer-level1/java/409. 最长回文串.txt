### 解题思路
     观察回文字符串的组成，可知只能出现1个个数为奇数的字符 ，可直接统计出现次数为奇数的字符的个数即可
### 代码

```java
class Solution {
    
    public int longestPalindrome(String s) {
        int ans = 0,sum = 0;
        int len = s.length();
        Map<Character,Integer> word = new HashMap<>();
        char[] sArray = s.toCharArray();
        for (char c : sArray) {
            word.put(c,word.containsKey(c)?word.get(c)+1:1);
        }
        Iterator it = word.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry entry = (Map.Entry) it.next();
            char key = (Character) entry.getKey();
            int value = (Integer) entry.getValue();
           //统计出现次数为奇数的字符的个数
           if(value%2!=0){
               sum++;
           }
        }
        if(sum == 0){
            ans = len;
        }else{
            ans = len-sum+1;
        }
        return ans;
    }
}
```