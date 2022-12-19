### 解题思路
- 根据size进行第一次分组放到Map中。
- 遍历Map，根据size大小对每个list进行等分。
[List等分参考地址](https://e.printstacktrace.blog/divide-a-list-to-lists-of-n-size-in-Java-8/)

### 代码

```java
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer, ArrayList<Integer>> intGroupMap = new HashMap<Integer, ArrayList<Integer>>();
        // Get map by groupSize
        for(int i = 0; i < groupSizes.length; i++) {
            if(!intGroupMap.containsKey(groupSizes[i])) {
                ArrayList<Integer> intList = new ArrayList<>();
                intList.add(i);
                intGroupMap.put(groupSizes[i], intList);
            }else {
                intGroupMap.get(groupSizes[i]).add(i);
            }
        }
        // Get detail list
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        for(Map.Entry m:intGroupMap.entrySet()){
           List<Integer> totalList = (ArrayList)m.getValue();
            int chunkSize = (int)m.getKey();
            for (int i = 0; i < totalList.size(); i += chunkSize) {
                result.add(totalList.subList(i,
                        Math.min(i + chunkSize, totalList.size())));
            }
        }
        return result;
    }
}
```