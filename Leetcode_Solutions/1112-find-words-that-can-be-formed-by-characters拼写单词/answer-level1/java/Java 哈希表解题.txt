### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if(chars.length() == 0) return 0;
        Map<Character,Integer> charsMap = new HashMap<>();
        Map<Character,Integer> wordMap = new HashMap<>();
        int result = 0,isAll = 0;
        saveAsMap(chars,charsMap);
        for(String s : words){
            saveAsMap(s,wordMap);
            for(Character key : wordMap.keySet()){
                if(wordMap.containsKey(key) && charsMap.containsKey(key)){
                    int a = wordMap.get(key);
                    int b = charsMap.get(key);
                    if(a <= b) continue;
                }
                isAll = 1;
                break;
                
            }
            if (isAll == 0) result += s.length();
            isAll = 0;
            wordMap = new HashMap<Character,Integer>();
        }
        return result;
        


    }

    public void saveAsMap(String s,Map<Character,Integer> map){
        for(int i = 0; i<s.length();i++){
            int num = 1;
            if (map.containsKey(s.charAt(i))){
                num = map.get(s.charAt(i));
                map.put(s.charAt(i),num+1);
            }else{
                map.put(s.charAt(i),num);
            }
        }
    }
}
```