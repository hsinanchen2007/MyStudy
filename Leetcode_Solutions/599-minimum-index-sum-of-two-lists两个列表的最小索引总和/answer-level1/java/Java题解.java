思路：
将其中一个 List 存入 HashMap 中，<Key:Value> 对应 <餐厅:索引>
对另一个 List 进行遍历，如果在 HashMap 中找到相同的餐厅就将其下标相加，检查是不是最小的

优化策略：
1. 选择 list1 和 list2 中长度较短的存入 HashMap，这样即节省空间也节省建立 HashMap 的时间
2. 对另一个 list 进行遍历时，如果当前遍历的索引值大于最小的索引和时，就可以结束遍历，返回结果

```java
public String[] findRestaurant(String[] list1, String[] list2) {
    //选择最短的 list 建立 HashMap
    String[] shortList = list1.length < list2.length ? list1 : list2;
    String[] longList = list1.length < list2.length ? list2 : list1;

    //记录最小索引和对应的餐厅
    List<String> resList = new ArrayList<>();

    //建立 HashMap，<Key:Value> 对应 <餐厅:索引>
    Map<String, Integer> map = new HashMap<>();
    for (int i = 0; i < shortList.length; i++) {
        map.put(shortList[i], i);
    }

    int minSum = Integer.MAX_VALUE;
    for (int i = 0; i < longList.length; i++) {
        //若当前索引大于最小索引和就停止遍历
        if (i > minSum) break;
        if (map.containsKey(longList[i])) {
            int indexSum = i + map.get(longList[i]);
            //若当前索引和小于最小索引和，则新建 resList 重新记录餐厅，并更新最小索引和
            if (minSum > indexSum) {
                resList = new ArrayList<>();
                resList.add(longList[i]);
                minSum = indexSum;
            }
            //若当前索引和等于最小索引和，则在当前 resList 后直接追加餐厅
            else if (minSum == indexSum) {
                resList.add(longList[i]);
            }
        }
    }

    String[] result = new String[resList.size()];
    for (int i = 0; i < result.length; i++) {
        result[i] = resList.get(i);
    }
    return result;
}
```
