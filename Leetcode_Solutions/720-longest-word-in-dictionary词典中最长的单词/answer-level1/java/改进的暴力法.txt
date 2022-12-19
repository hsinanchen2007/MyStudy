
# 改进的暴力法

和官方题解的暴力法思路类似，但是把Set换成Map，用来存储当前单词的前缀是否全部存在，这样就不用重复判断，每个单词就只需要判断一次即可。

```java

class Solution {
    public boolean isValid(Map<String,Integer> s, String str){

        Integer i = s.get(str);
        if(i == null) {
            return false;
        }else{
            if(i>0){
                return true;
            }else if(i==0){
                if(str.length()==1) {
                    s.put(str,1);
                    return true;
                }else{
                    boolean r = isValid(s, str.substring(0, str.length() -1));
                    if(r){
                        s.put(str,1);
                    }else{
                        s.put(str,-1);
                    }
                    return r;
                }
            }else{
                return false;
            }
        }

    }

    public String longestWord(String[] words) {
        if(words.length == 0) return "";
        Map<String,Integer> strings = new HashMap<>();
        for (String word : words) {
            strings.put(word,0);
        }
        int max = 0;
        String longestStr = "";
        
        for (Map.Entry<String, Integer> entry : strings.entrySet()) {
            String key = entry.getKey();
            if(isValid(strings,key) && key.length() >= max){
                if(key.length() > max){
                    max= key.length();
                    longestStr = key;
                }else{
                    if(key.compareTo(longestStr) < 0){
                        longestStr = key;
                    }
                }
            }
        }
        return longestStr;


    }
}
```