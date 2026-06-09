# 思路：
简而言之：根据**下标集合**，去构建**字符集合**。将**下标集合**与**字符集合**  分别**排序**，将排好序的**下标**和**字符**  **一一对应**即可。
形象点说：从**排好序**的**下标集合**中 **从左往右**地取出对应字符，再将所有取出的字符  **排序**，最后把排好序的字符**从左到右**插入回下标集合中的下标中。

1. 先找出所有能 互换 位置的 **下标集合**
2. 遍历**所有** **下标集合**：
将**当前** **下标集合**中所有下标对应的字符“**抽出**”，构成1个**字符集合**；
将**字符集合** **排序**(字典序)
将**字符集合** **按顺序**(**从左到右**)  **插入**回原字符串。



下标 ***0*** 1 ***2 3***
字符 ***b*** d ***a c***
能互换的下标集合为{0, 2, 3}，则取下标对应字符 作为1个**字符集合**{b, a, c}，
将**字符集合**  **排序**，得{a, b, c}，
按序插入回原字符串，得：
下标 ***0*** 1 ***2 3***
字符 ***a*** d ***b c***

# 代码
```java
class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int len = s.length();

        DSU dsu = new DSU(100000);
        //构造下标集合
        for (List<Integer> list : pairs)
            dsu.union(list.get(0), list.get(1));
        //每个下标集合有1个leader，用leader作为key(唯一)，下标集合List作为value
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        //从小到大遍历，使得List<Integer>中的值是有序的(事后不用再排序了)
        for (int i = 0; i < len; ++i) {
            int key = dsu.find(i);
            map.computeIfAbsent(key, unused -> new ArrayList<>()).add(i);
        }

        StringBuilder res = new StringBuilder(s);
        //遍历所有每个下标集合，进行字符局部排序
        for (List<Integer> idx_list : map.values())
            if (idx_list.size() > 1)
                sort(res, idx_list);

        return res.toString();
    }

    //根据下标集合进行局部排序
    private void sort(StringBuilder res, List<Integer> idx_list) {
        int len = idx_list.size();
        char[] array = new char[len];
        //根据下标集合构建字符集合
        for (int i = 0; i < len; ++i)
            array[i] = res.charAt(idx_list.get(i));
        //将字符集合排序
        Arrays.sort(array);
        //将字符按序“插入”回StringBuilder
        for (int i = 0; i < len; ++i)
            res.setCharAt(idx_list.get(i), array[i]);
    }
}

class DSU {
    int[] parent;

    public DSU(int len) {
        parent = new int[len];
        for (int i = 0; i < len; ++i)
            parent[i] = i;
    }

    public int find(int x) {
        return parent[x] != x ? parent[x] = find(parent[x]) : x;
    }

    public void union(int x, int y) {
        parent[find(x)] = find(y);
    }
}
```

