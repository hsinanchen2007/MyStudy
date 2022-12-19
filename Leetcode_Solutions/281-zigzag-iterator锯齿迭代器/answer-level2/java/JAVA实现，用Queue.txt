
将List变成Queue，放入LinkedList中。
1. next
则取第一个Queue的第一个元素。
取完后：1.Queue仍然有值则放到最后；2.Queue为空则抛弃。
2. hasNext
因为Queue为空则抛弃，元素遍历完后整个LindedList是空的。


```java 
public class ZigzagIterator extends LinkedList<Queue<Integer>> {

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        if (!v1.isEmpty()) add(new LinkedList<>(v1));
        if (!v2.isEmpty()) add(new LinkedList<>(v2));
    }

    public int next() {
        // 取出并删除第一个list的第一个元素
        Queue<Integer> first = poll();
        Integer poll = first.poll();

        // 如果list不为空，则放到最后
        if (!first.isEmpty()) add(first);
        return poll;
    }

    public boolean hasNext() {
        return !isEmpty();
    }

    public static void main(String[] args) {
        List<Integer> v1 = Arrays.asList(1, 2);
        List<Integer> v2 = Arrays.asList(3, 4, 5, 6);
        ZigzagIterator z = new ZigzagIterator(v1, v2);
        while (z.hasNext()) {
            System.err.println(z.next());
        }
    }
}
```

