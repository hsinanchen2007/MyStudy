### 解题思路
难得通过

### 代码

```java
class Solution {

    public static List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> map = new HashMap<>();
        // Arrays.sort(words);
        for (String str:words) {
            if (!map.containsKey(str)){
                map.put(str,1);
            }else{
                map.put(str,map.get(str)+1);
            }
        }

        List<String> list = new ArrayList<>();
        for (int i=0;i<k;i++) {
            list.add(getMaxAndRemove(map));
        }
        return list;

    }
    
    public static String getMaxAndRemove(Map<String,Integer> map) {
        Iterator<Map.Entry<String,Integer>> iterator = map.entrySet().iterator();

        int max = 0;
        String maxStr="";

        while (iterator.hasNext()) {
            Map.Entry<String, Integer> item = iterator.next();
            if (item.getValue()>max) {
                max = item.getValue();
                maxStr = item.getKey();
            }else if (item.getValue()==max&&maxStr.compareTo(item.getKey())>0){
                maxStr = item.getKey();
            }
        }
        map.remove(maxStr);
        
        return maxStr;
    }
}
```