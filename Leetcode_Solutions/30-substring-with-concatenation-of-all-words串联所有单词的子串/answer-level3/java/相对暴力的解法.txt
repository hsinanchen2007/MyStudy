### 解题思路
```java
System.out.println();
// 这原来也是消耗时间的
```
### 代码

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {

        List<Integer> ans = new ArrayList<Integer>();
        if (s.length() == 0 || words.length == 0) {
            return ans;
        }
        HashMap<String, Integer> wordMap = new HashMap<String, Integer>();
        for(String word: words){
            if(wordMap.containsKey(word)){
                wordMap.put(word, wordMap.get(word)+1);
            }
            else {
                wordMap.put(word, 1);
            }
        }
        int wordLen = words[0].length();
        int totalLen = wordLen * words.length;
        for(int i = 0; i < s.length()- totalLen+1; i++){
            String tmp = s.substring(i, totalLen + i);
            HashMap<String, Integer> tmpMap = new HashMap<String, Integer>(wordMap);

            for (int j = 0; j<tmp.length(); j+=wordLen){
                String tmpStr = tmp.substring(j, wordLen+ j);
                if (tmpMap.containsKey(tmpStr)){
                    tmpMap.put(tmpStr, tmpMap.get(tmpStr)- 1);
                    if(tmpMap.get(tmpStr) == 0){
                        tmpMap.remove(tmpStr);}
                
                }
                else{
                    break;
                }
            }
            if(tmpMap.isEmpty()){
                ans.add(i);
            }

        }

        
        return ans;
    }
}
```