### 代码

```java
public class NestedIterator implements Iterator<Integer> {

    private List<Integer> record = new ArrayList<>();
    private int index;

    public NestedIterator(List<NestedInteger> nestedList) {
        index = 0;
        dfs(nestedList);
    }

    @Override
    public Integer next() {
        return record.get(index++);
    }

    @Override
    public boolean hasNext() {
        return index != record.size();
    }

    private void dfs(List<NestedInteger> nestedList) {
        for (NestedInteger nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                record.add(nestedInteger.getInteger());
            } else {
                dfs(nestedInteger.getList());
            }
        }
    }

}
```