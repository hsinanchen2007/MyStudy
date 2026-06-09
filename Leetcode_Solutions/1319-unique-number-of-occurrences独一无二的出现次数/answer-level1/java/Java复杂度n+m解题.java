```
        // 先找到所有的数字及出现的次数，放到map中
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : arr) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }
        // 再遍历map的所有value，放到list中判断是否有重复
        List<Integer> list = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (list.contains(entry.getValue())) {
                return false;
            } else {
                list.add(entry.getValue());
            }
        }
        return true;
```
