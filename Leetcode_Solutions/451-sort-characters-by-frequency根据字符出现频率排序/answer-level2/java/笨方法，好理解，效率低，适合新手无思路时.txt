### 解题思路
1.统计次数，用MAP。
2.这里的难点是对Map的value进行排序，Map本身是无序的，这里我们要把MAP转成Map.Entry的List，了解map底层实现的都知道，map的key和value是包装成Entry这个内部类的。
3.对value排序
4.遍历list生成新的String。

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        //对map根据value排序，无法直接排序，可以将map转化成list，然后排序
        List<Map.Entry<Character, Integer>> list = new ArrayList<>(map.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<Character, Integer>>() {
            @Override
            public int compare(Map.Entry<Character, Integer> o1, Map.Entry<Character, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        });
        StringBuffer stringBuffer = new StringBuffer();
        for (int i = 0; i < list.size(); i++) {
            Map.Entry entry = list.get(i);
            for (int j = 0; j < (int) entry.getValue(); j++) {
                stringBuffer.append(entry.getKey());
            }
        }
        return stringBuffer.toString();
    }
}
```