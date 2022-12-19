### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> computeSimilarities(int[][] docs) {
        List<String> ll = new LinkedList<>();
        HashMap<Integer, List<Integer>> hm = new HashMap();
        HashMap<String, Integer> hm2 = new LinkedHashMap<>();
        int[][] res = new int[docs.length][docs.length];
        for (int i = 0; i < docs.length; i++) {
            for (int j = 0; j < docs[i].length; j++) {
                if (hm.containsKey(docs[i][j])) {
                    for (int k : hm.get(docs[i][j])) {
                        hm2.put(i + "," + k, 0);
                        res[i][k]++;
                    }
                    hm.get(docs[i][j]).add(i);
                } else {
                    List<Integer> tl = new LinkedList<>();
                    tl.add(i);
                    hm.put(docs[i][j], tl);
                }
            }
        }
        hm2.forEach((s, k) -> {
            int i = Integer.parseInt(s.split(",")[0]);
            int j = Integer.parseInt(s.split(",")[1]);
            ll.add("" + j + "," + i + ": "
                + String.format("%.4f", (res[i][j] + 0.0) / (docs[i].length + docs[j].length - res[i][j])));
        });

        return ll;
    }
}
```