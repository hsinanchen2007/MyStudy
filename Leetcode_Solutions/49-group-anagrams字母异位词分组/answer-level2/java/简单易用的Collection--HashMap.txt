### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<Map<String,Integer>,List<String>> resultMap= new HashMap<>();
        for(int strsPtr = 0; strsPtr < strs.length; strsPtr++) {
            Map<String, Integer> strMap = new HashMap<>();

            for(int strPtr = 0; strPtr < strs[strsPtr].length(); strPtr++) {
                String tempS = strs[strsPtr].substring(strPtr, strPtr + 1);
                if(strMap.containsKey(tempS)) {
                    strMap.put(tempS, strMap.get(tempS) + 1);
                } else {
                    strMap.put(tempS, 1);
                }
            }

            if(resultMap.containsKey(strMap)) {
                resultMap.get(strMap).add(strs[strsPtr]);
            } else {
                List<String> temp = new ArrayList<String>();
                temp.add(strs[strsPtr]);
                resultMap.put(strMap, temp);
            }
        }

        return new ArrayList<List<String>>(resultMap.values());
    }
}
```