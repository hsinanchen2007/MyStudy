- peek：直接返回头指针的元素
- next：头指针后移,返回头指针的元素
- hasNext：头指针是否和尾指针重叠
- grow函数中每次容量扩大两倍,同时判断扩容时是否移除
```
class PeekingIterator implements Iterator<Integer> {

    private int size = 8;
    private Integer[] elements = new Integer[size];
    // p指向当前元素
    private int p = 0;
    // q指向最后一个元素的下一个索引
    private int q = p;

    public PeekingIterator(Iterator<Integer> iterator) {
        while (iterator.hasNext()) {
            if (q == size) {
                grow();
            }
            elements[q++] = iterator.next();
        }
    }

    public Integer peek() {
        return elements[p];
    }

    @Override
    public Integer next() {
        return elements[p++];
    }

    @Override
    public boolean hasNext() {
        return p != q;
    }

    private void grow() {
        int newSize = size > Integer.MAX_VALUE >> 1 ? Integer.MAX_VALUE : size << 1;
        Integer[] objects = new Integer[newSize];
        System.arraycopy(elements, 0, objects, 0 , size);
        size = newSize;
        elements = objects;
    }
}
```
---------------------------------------------------------
这道题是简单难度才对