```java
class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> res = new ArrayList<>();
        TreeMap<String, Integer> map = new TreeMap<>();
        Arrays.sort(products);
        List<String> list = Arrays.asList(products);
        for (int i = 0; i < products.length; i ++) {
            map.put(products[i], i);
        }
        String key = "";
        for (char c : searchWord.toCharArray()) {
            key += c;
            String ceil = map.ceilingKey(key);
            String floor = map.floorKey(key + "~");
            if (ceil == null || floor == null) break;
            res.add(list.subList(map.get(ceil), Math.min(map.get(ceil) + 3, map.get(floor) + 1)));
        }
        while (res.size() < searchWord.length()) res.add(new ArrayList<>());
        return res;
    }
}
```