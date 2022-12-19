这道题乍一看很眼熟，就是格雷码的产生过程。但是要求必须是从start开始。因此，比较简单的一种做法是连续生成两遍格雷码，然后找到元素start第一次出现的位置，返回该位置及其后共计2 ^ n个元素的子列表即可。
```
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> list = new LinkedList<>();
        int max = ~(-1 << n), cnt = 0;
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i <= max; i++) {
                list.add(i ^ i >> 1);
            }
        }
        int left = list.indexOf(start);
        return list.subList(left, max + left + 1);
    }
```
