执行时间：4ms，98%；内存：36.7MB，93.59%。

简单粗暴，在初始化迭代器的时候就直接把结果遍历出来，递归遍历列表中的数据，是整数就放入List，不是则再递归遍历，代码结构简单。

```java
public class NestedIterator implements Iterator<Integer> {

    private List<Integer> list;
    private int index;

    public NestedIterator(List<NestedInteger> nestedList) {
        list = integerIterator(nestedList);
        index = -1;
    }

    @Override
    public Integer next() {
        if (this.hasNext())  return list.get(++index);
        return null;
    }

    @Override
    public boolean hasNext() {
        if (index + 1 < list.size()) return true;
        return false;
    }

    private static List<Integer> integerIterator(List<NestedInteger> nestedIntegerList) {
        ArrayList<Integer> list = new ArrayList<>(nestedIntegerList.size());
        for (NestedInteger tmp : nestedIntegerList) {
            if (tmp.isInteger()) 
                list.add(tmp.getInteger());
            else 
                list.addAll(integerIterator(tmp.getList()));
        }
        return list;
    }
}
```
