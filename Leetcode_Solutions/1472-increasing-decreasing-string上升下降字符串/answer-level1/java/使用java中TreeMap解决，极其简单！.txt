### 解题思路
主要利用java中有序TreeMap特性实现，从小到大（higherEntry）和从大到小（lowerEntry）交替筛选，被筛选一次则将value减1，直至value为0时移除该键值对，重复过程直至TreeMap的元素个数为0，返回结果。

### 代码

```java
class Solution {
    public String sortString(String s) {
        //将字符串按照各字符大小装入TreeMap中，key为字符，value为出现次数
        TreeMap<Character, Integer> params = new TreeMap<>(Comparator.comparingInt(Character::charValue));
        for (char item: s.toCharArray()) {
            if(params.containsKey(item)){
                params.put(item, params.get(item)+1);
            }else {
                params.put(item, 1);
            }
        }

        StringBuilder result = new StringBuilder();
        Boolean desc = true;
        //由题意知结果字符串为先从小到大筛选各字符排列，然后从大到小筛选排列，然后又从小到大筛选排列，直至全部筛选完
        //故此可利用有序treeMap的higherEntry和lowerEntry方法进行筛选获取
        Map.Entry<Character, Integer> entry = params.firstEntry();
        Map.Entry<Character, Integer> temp = entry;
        while (params.size() > 0){
            if(entry != null){
                result.append(entry.getKey());
                if(entry.getValue() > 1){
                    params.put(entry.getKey(), entry.getValue()-1);
                }else {
                    params.remove(entry.getKey());
                }
            }else {
                desc = !desc;
            }
            if(desc){
                entry = (entry != null ?params.higherEntry(entry.getKey()) : params.firstEntry());
            }else {
                entry = (entry != null ?params.lowerEntry(entry.getKey()) : params.lastEntry());
            }

        }
        return result.toString();
    }
}
```