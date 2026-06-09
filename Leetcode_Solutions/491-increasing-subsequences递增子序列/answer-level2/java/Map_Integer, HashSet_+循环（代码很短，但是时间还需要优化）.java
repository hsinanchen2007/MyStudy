map中key代码以某个数字结尾的递增子串集合,当遍历到某个数i时候只需要将key<=i的HashSet中的String后添加i即可。遗憾的是时间消耗过多，因为需要对HashSet中的结果进行处理。还可以继续优化。
```java []
public List<List<Integer>> findSubsequences(int[] nums) {
        Map<Integer, HashSet<String>> map = new HashMap<>();// Key代表以该数结尾的子串
        IntStream.of(nums).forEach(i -> {
            HashSet<String> setSumI = new HashSet<>();
            Stream.concat(map.keySet().stream().filter(item -> item < i), Stream.of(i)).forEach(key -> {
                if (key == i && !map.keySet().contains(key)) {
                    map.put(key, new HashSet<>());
                    map.get(key).add(i + ",");
                    return;
                }
                map.get(key).forEach(str -> setSumI.add(str + i + ","));
            });
            setSumI.stream().forEach(map.get(i)::add);
        });
        List<List<Integer>> list = new ArrayList<>();
        map.keySet().stream().forEach(j -> map.get(j).stream().filter(str -> str.split(",").length > 1).forEach(str -> {
            List<Integer> listEle = new ArrayList<>();
            Stream.of(str.split(",")).forEach(num -> listEle.add(Integer.parseInt(num)));
            list.add(listEle);
        }));
        return list;
    }
```
```
