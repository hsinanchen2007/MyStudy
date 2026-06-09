### 解题思路
思路就是利用2个Map，其中一个维护chars字符串中每个字符出现的次数，另外一个维护每个字符串中每个字符的出现次数，然后取其中一个Map中的key，去另外一个Map中比对就可以了，比较粗暴和浪费空间，其实可以利用数组下标去统计chars字符串中每个字符的出现次数，0对应a，1对应b······

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if(words.length == 0 || chars.length() == 0)
            return 0;
        int result = 0;
        Map<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < chars.length(); i++){
            Character ch = chars.charAt(i);
            if(!map.containsKey(ch))
                map.put(ch, 1);
            else
                map.put(ch, map.get(ch) + 1);
        }
        for(int i = 0; i < words.length; i++){
            boolean flag = true;
            Map<Character, Integer> tmp = new HashMap<>();
            String word = words[i];
            for(int j = 0; j < word.length(); j++){
                Character ch = word.charAt(j);
                if(!tmp.containsKey(ch))
                    tmp.put(ch, 1);
                else
                    tmp.put(ch, tmp.get(ch) + 1);
            }
            Set<Character> set = tmp.keySet();
            for(Character ch : set){
                if(map.get(ch) == null || tmp.get(ch) > map.get(ch))
                    flag = false;
            }
            if(flag)
                result += word.length();
        }
        return result;
    }
}
```