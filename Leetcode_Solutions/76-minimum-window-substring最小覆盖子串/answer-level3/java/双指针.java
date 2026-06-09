### 解题思路
主要是比较剩余的多少字，滑动窗口来做。

### 代码

```java
class Solution {
    public String minWindow(String s, String t) {
        HashMap<Character, Integer> countMap = new HashMap();
        for(Character c : t.toCharArray()){
            if(countMap.containsKey(c)){
                countMap.put(c, countMap.get(c)+1);
            }else{
                countMap.put(c, 1);
            }
        }
        HashMap<Character, Integer> resMap = new HashMap();
        char[] array = s.toCharArray();
        int i = 0;
        int j = 0;
        int start = 0;
        int end = array.length-1;
        int leftWords = t.toCharArray().length;
        while(j < array.length){
            char curWord = array[j];
            if(countMap.containsKey(curWord)){
                if(resMap.containsKey(curWord)){
                    int curCount = resMap.get(curWord);
                    resMap.put(curWord, curCount+1);
                    if(curCount+1 <= countMap.get(curWord)) leftWords--;
                }else{
                    resMap.put(curWord, 1);
                    leftWords--;
                }
                
            }
            while(leftWords == 0){
                char curStartWord = array[i];
                if(resMap.containsKey(curStartWord)){
                    int tcount = countMap.get(curStartWord);
                    int scount = resMap.get(curStartWord);
                    if(scount > tcount){
                        resMap.put(curStartWord, scount-1);
                    }else{
                        break;
                    }
                }
                i++;
            }
            if(leftWords == 0 && (j - i) < (end - start)){
                start = i;
                end = j;
            }
            j++;
        }
        return leftWords == 0 ? s.substring(start, end+1) : "";
    }
}
```