### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map = new HashMap<>();
        List<String> list = new ArrayList<>();
        Map<String, Integer> resultLists = new HashMap<>();
        for (int i = 0; i < list1.length; i++) {
            map.put(list1[i], i);
        }

        for (int i = 0; i < list2.length; i++) {
            if (map.containsKey(list2[i])) {
                resultLists.put(list2[i], i + map.get(list2[i]));
            }
        }

        List<Map.Entry<String, Integer>> sortTo = new ArrayList<>(resultLists.entrySet());
        Collections.sort(sortTo, new Comparator<Map.Entry<String, Integer>>() {

            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o1.getValue().compareTo(o2.getValue());
            }
        });


        Set<String> set = new HashSet<>();
        int index = 0;
        int first = 0;
        for (Map.Entry s : sortTo) {
            if (index == 0) {
                first = (int)s.getValue();
                set.add((String) s.getKey());
                System.out.println(first);
            } else {
                if ((int)s.getValue() == first) {
                    set.add((String) s.getKey());
                } else {
                    break;
                }
            }
            index++;
        }
        String[] results = new String[set.size()];
        int size = 0;
        Iterator iterator = set.iterator();
        while (iterator.hasNext()) {
            results[size++] = (String) iterator.next();
        }

        return results;
    }
}
```