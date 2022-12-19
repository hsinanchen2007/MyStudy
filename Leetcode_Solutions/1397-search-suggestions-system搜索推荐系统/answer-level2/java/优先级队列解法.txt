对于每个搜索关键词，对product进行遍历，将前缀相同的字符串放入优先级队列中。

遍历完成后，取出优先级最高（即按字母序）的三个字符串。
```java
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        if (products == null || searchWord == null) return null;

        List<List<String>> ret = new ArrayList<>();
        for (int i = 0; i < searchWord.length(); i++) {
            String keyword = searchWord.substring(0, i + 1);
            PriorityQueue<String> queue = new PriorityQueue<>();
            for (String s : products) {
                if (s.indexOf(keyword) == 0) {
                    queue.add(s);
                }
            }
            List<String> list = new ArrayList<>();

            while (!queue.isEmpty() && list.size() != 3) {
                list.add(queue.poll());
            }
            ret.add(list);
        }
        return ret;
    }
```
