### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        for(int i = 0; i < chars.length(); i++){
            if(map.containsKey(chars.charAt(i))){
                map.replace(chars.charAt(i), map.get(chars.charAt(i)), map.get(chars.charAt(i)) + 1);
            }else{
                map.put(chars.charAt(i), 1);
            }
        }
        int ans = 0;
        for(String word : words){
            HashMap<Character, Integer> map_word = new HashMap<Character, Integer>();
            for(int i = 0; i < word.length(); i++){
                if(map_word.containsKey(word.charAt(i))){
                    map_word.replace(word.charAt(i), map_word.get(word.charAt(i)), map_word.get(word.charAt(i)) + 1);
                }else{
                    map_word.put(word.charAt(i), 1);
                }
            }
            boolean isCommand = true;
            for (Character key : map_word.keySet()) {
                Integer value = map_word.get(key);
                if(!map.containsKey(key) || map.get(key) < value){
                    isCommand = false;
                    break; 
                }
		    }
            if(isCommand){
                ans += word.length();
            }   
        }
        return ans;
    }
}
```