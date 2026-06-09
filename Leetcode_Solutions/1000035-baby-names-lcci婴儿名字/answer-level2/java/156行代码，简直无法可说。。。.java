### 解题思路
用一个并查集，把名字串起来，建立一个Map索引名字和并查集的index。
将并差集名字整成一个set，每一个元素插入计数。
过程那么点负责，思路清晰，就是写起来有点累。。。

### 代码

```java
class Solution {
    private class UnionFind {
        int size;
        int[] dage;

        public UnionFind(int size) {
            this.size = size;
            dage = new int[size];
            for (int i = 0; i < size; i++) {
                dage[i] = i;
            }
        }
        public int find(int element) {
            return dage[element];
        }

        public void union(int first, int second) {
            int dageF = find(first);
            int dageS = find(second);

            if (dageF == dageS) {
                return;
            }

            for (int i = 0; i < size; i++) {
                if (dage[i] == dageF) {
                    dage[i] = dageS;
                }
            }
        }

        public List<Set<Integer>> getCircles() {
            Map<Integer, Set<Integer>> map = new HashMap<>();
            for (int i = 0; i < size; i++) {
                int key = find(i);
                if (map.keySet().contains(key)) {
                    Set<Integer> tmp = map.get(key);
                    tmp.add(i);
                    map.put(key, tmp);
                } else {
                    Set<Integer> tmp = new HashSet<>();
                    tmp.add(i);
                    map.put(key, tmp);
                }
            }
            return  new ArrayList<>(map.values());
        }

    }

    private List<String> splitNames(String input) {
        int dotIndex = input.indexOf(',');
        String name1 = input.substring(1, dotIndex);
        String name2 = input.substring(dotIndex + 1, input.length() - 1);
        List<String> result = new ArrayList<>();
        result.add(name1);
        result.add(name2);
        return result;
    }

    private String getMinName(Set<Integer> set, Map<Integer, String> map) {
        List<Integer> list = new ArrayList<>();
        list.addAll(set);
        String result = map.get(list.get(0));
        for (int i = 1; i < list.size(); i++) {
            String name = map.get(list.get(i));
            if (name.compareTo(result) < 0) {
                result = name;
            }
        }
        return result;
    }

    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        Map<String, Integer> nameMap = new HashMap<>();
        Integer ufIndex = 0;
        for (String name2 : synonyms) {
            List<String> nameList = splitNames(name2);
            for (String name : nameList) {
                if (!nameMap.keySet().contains(name)) {
                    nameMap.put(name, ufIndex++);
                }
            }
        }

        UnionFind uf = new UnionFind(nameMap.size());
        for (String name2 : synonyms) {
            List<String> nameList = splitNames(name2);
            String n1 = nameList.get(0);
            String n2 = nameList.get(1);
            Integer i1 = nameMap.get(n1);
            Integer i2 = nameMap.get(n2);
            uf.union(i1, i2);
        }

        List<Set<Integer>> circles = uf.getCircles();

        Map<Set<Integer>, Integer> resMap = new HashMap<>();
        for (Set<Integer> tmpSet : circles) {
            resMap.put(tmpSet, 0);
        }

        Map<String, Integer> freshNameMap = new HashMap<>();
        for (String namess : names) {
            int index_ = namess.indexOf('(');
            String name = namess.substring(0, index_);
            String timesStr = namess.substring(index_ + 1, namess.length() - 1);
            Integer times = Integer.parseInt(timesStr);

            Integer nameIndex = nameMap.get(name);
            if (nameIndex == null) {
                if (freshNameMap.containsKey(name)) {
                    freshNameMap.put(name, freshNameMap.get(name) + times);
                } else {
                    freshNameMap.put(name, times);
                }
                continue;
            }
            for (Set<Integer> tmpName : circles) {
                if (tmpName.contains(nameIndex)) {
                    resMap.put(tmpName, resMap.get(tmpName) + times);
                    break;
                }
            }
        }

        Map<Integer, String> indexMap = new HashMap<>();
        for (Map.Entry<String, Integer> tmp : nameMap.entrySet()) {
            indexMap.put(tmp.getValue(), tmp.getKey());
        }

        Map<String, Integer> resultMap = new HashMap<>();
        for (Map.Entry<Set<Integer>, Integer> tt : resMap.entrySet()) {
            Set<Integer> key = tt.getKey();
            Integer value = tt.getValue();
            String minName = getMinName(key, indexMap);
            resultMap.put(minName, value);
        }

        for (Map.Entry<String, Integer> fresh : freshNameMap.entrySet()) {
            resultMap.put(fresh.getKey(), fresh.getValue());
        }

        String[] result = new String[resultMap.size()];
        int count = 0;
        for (Map.Entry<String, Integer> res : resultMap.entrySet()) {
            String key = res.getKey();
            Integer value = res.getValue();
            String tmp = key + "(" + value + ")";
            result[count++] = tmp;
        }

        Arrays.sort(result);
        return result;
    }
}
```