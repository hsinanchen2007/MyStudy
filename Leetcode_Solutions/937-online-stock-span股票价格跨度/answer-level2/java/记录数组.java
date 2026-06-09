```
class StockSpanner {

    private List<Integer> records = new ArrayList<>();
    private List<Integer> results = new ArrayList<>();

    public StockSpanner() {

    }

    public int next(int price) {
        int spinner = 1;
        for (int i = records.size() - 1; i >= 0; ) {
            if (records.get(i) > price) {
                break;
            }

            if (records.get(i) == price) {
                spinner += results.get(i);
                break;
            }

            spinner += results.get(i);
            i -= results.get(i);
        }
        records.add(price);
        results.add(spinner);
        return spinner;
    }
}
```
![image.png](https://pic.leetcode-cn.com/37548c754230df14238d246c5522ef08be7a123d4b05cd7c6d5d9a0cae314881-image.png)
