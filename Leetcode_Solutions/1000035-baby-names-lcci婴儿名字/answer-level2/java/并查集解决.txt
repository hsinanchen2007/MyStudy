### 解题思路
并查集走一波，就是判断条件变了。哈哈哈

### 代码

```java
class Solution {
    private Map<String, String> fatherMap = new HashMap<>();

    private Set<String> set = new HashSet<>();

    private Map<String, Integer> rank = new HashMap<>();

    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        for (String str : names) {
            String name = str.substring(0, str.indexOf("("));
            String num = str.substring(str.indexOf("(") + 1, str.indexOf(")"));
            fatherMap.put(name,name);
            set.add(name);
            rank.put(name, Integer.parseInt(num));
        }

        for (String str : synonyms) {
            String[] namesArr = str.substring(str.indexOf("(") + 1, str.indexOf(")")).split(",");
            if (rank.containsKey(namesArr[0]) && rank.containsKey(namesArr[1])) {
                union(namesArr[0], namesArr[1]);    
            }
        }
        ArrayList<String> ansList = new ArrayList<>();
        for (String name : set) {
            ansList.add(name + "(" + rank.get(name) + ")");
        }
        String[] ans = new String[ansList.size()];
        for (int i = 0, len = ansList.size(); i < len; i++) {
            ans[i] = ansList.get(i);
        }
        return ans;
    }


    public void union(String a, String b) {
        String big = findFather(a);
        String small = findFather(b);
        if (big.equals(small)) {
            return;
        }
        if (small.compareTo(big) > 0) {
            String temp = small;
            small = big;
            big = temp;
        }
        fatherMap.put(big, small);
        rank.put(small, rank.get(big) + rank.get(small));
        set.remove(big);
    }

    public boolean isConnected(String a, String b) {
        return findFather(a).equals(findFather(b));
    }

    /**
     *
     * @param child
     * @return
     */
    private String findFather(String child) {
        Stack<String> path = new Stack<>();
        String father = fatherMap.get(child);
        if (father == null) {
            throw new IllegalArgumentException("child does not exist.");
        }
        while (!father.equals(child)) {
            path.push(father);
            child = father;
            father = fatherMap.get(child);
        }
        while (path.size() > 0) {
            String t = path.pop();
            fatherMap.put(t, father);
        }
        return father;
    }
}
```