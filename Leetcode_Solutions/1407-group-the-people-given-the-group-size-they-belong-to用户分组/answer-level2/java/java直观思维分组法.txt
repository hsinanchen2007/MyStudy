最简单的思路：把输入的值作为key，数组下标的集合作为value构建一个map，构建好后将value长度大于key值的list分割即可
```
public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> result = new ArrayList<>();
        int len = groupSizes.length;
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            int key = groupSizes[i];
            List<Integer> valueList = map.get(key);
            if (valueList == null) {
                valueList = new ArrayList<>();
            }
            valueList.add(i);
            map.put(key, valueList);
        }

        for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {
            int key = entry.getKey();
            List<Integer> value = entry.getValue();
            for(int i = 0; i < (value.size() / key); i++){
                List<Integer> tempList = new ArrayList<>();
                for(int j = i * key; j < (i * key + key); j++){
                    tempList.add(value.get(j));
                }
                result.add(tempList);
            }
        }
        return result;
    }
```
