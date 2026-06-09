
使用数组实现链表 -> 静态链表：
- 静态链表对数组的第一个元素和最后一个元素(或者第二个元素)做特殊元素处理，不存数据
- 通常未被使用的数组元素称为备用链表，即默认备用链表从index=1开始
- 数组的第一个元素即index=0的元素存储备用链表的第一个结点下标
- 数组最后一个元素存储第一个有数值元素的下标，即相当于单链表的头结点，当链表为空时，值为1
 ```
public class ArrayLinked<E> {

    /**
     * 创建静态数组
     */
    private Node<E>[] elementData;
    private static final int MAX_SIZE = 12;
    private int length;

    public ArrayLinked() {
        init();
    }

    /**
     * 静态链表初始化
     */
    private void init() {
        elementData = new Node[MAX_SIZE];
        int len = elementData.length - 1;
        for (int i = 0; i < len; i++) {
            elementData[i] = new Node<>(i + 1);
        }
        //最后一个元素存储第一个存储数值元素的下标
        elementData[len] = new Node<>(1);
    }

    /**
     * 添加元素
     *
     * @param e
     */
    public void add(E e) {
        int cur = getSpaceCur();
        elementData[cur].e = e;
        ++length;
    }

    /**
     * 插入元素
     * @param cur  插入元素的索引
     * @param e 插入的原宿
     */
    public void insert(int cur, E e) {
        checkIndex(cur);
        int start = MAX_SIZE-1;
        //获取到插入元素的位置
        for (int i=0;i<cur;i++){
            start=elementData[start].cur;
        }
        //获取到插入位置元素的上一个元素
        Node<E> pre = elementData[start];
        //获取到备用链表位置
        int i = getSpaceCur();
        //备用链表位置插入存储元素
        elementData[i].e=e;
        //将插入元素的下一个位置指向插入前元素的位置
        elementData[i].cur=pre.cur;
        //将插入前元素的位置的上一个位置的元素指向插入元素
        pre.cur=i;
        ++length;
    }

    /**
     * 删除
     *
     * @param cur 删除索引
     * @return 删除前的元素
     */
    public E remove(int cur) {
        checkIndex(cur);
        //最后一个位置，保存第一个存有值的元素位置
        int start = MAX_SIZE - 1;
        for (int i = 0; i < cur; i++) {
            start = elementData[start].cur;
        }
        //得到删除元素的上一个元素
        Node<E> pre = elementData[start];
        int i = pre.cur;
        //得到删除元素
        Node<E> current = elementData[i];
        //将删除元素的上一个元素指向删除元素的下一个元素
        pre.cur = current.cur;
        //释放删除元素
        free(i);
        return current.e;
    }

    /**
     * 回收 将cur 位置的元素回收，将该位置作为备用链表新的起始位置
     * 将原来备用链表的位置作为该位置的下一个
     * 可以将该位置的元素置为null，也可不置为null，反正添加时会覆盖
     * 这里没有置为null
     *
     * @param cur 回收位置
     */
    private void free(int cur) {
        Node<E> head = elementData[0];
        elementData[cur].cur = head.cur;
        head.cur = cur;
        --length;
    }

    /**
     * 获取元素
     *
     * @param cur 元素索引
     * @return 元素
     */
    public E get(int cur) {
        checkIndex(cur);
        int start = elementData[MAX_SIZE - 1].cur;
        for (int i = 0; i < cur; i++) {
            start = elementData[start].cur;
        }
        return elementData[start].e;
    }

    private void checkIndex(int cur) {
        if (cur < 0 || cur >= length) {
            throw new IndexOutOfBoundsException();
        }
    }

    /**
     * 获取备用链表的位置
     * 并将备用链表位置后移
     * @return
     */
    private int getSpaceCur() {
        //获取备用链表位置
        int i = elementData[0].cur;
        Node<E> spaceNode = elementData[i];
        //将备用链表位置移动到下一个分量
        elementData[0].cur = spaceNode.cur;
        return i;
    }

    /**
     * 返回链表的长度 即包含元素的个数
     * @return
     */
    public int length(){
        return  length;
    }

    private static class Node<E> {
        /**
         * 元素
         */
        E e;
        /**
         * 下一个元素的索引
         */
        int cur;

        public Node(E e, int cur) {
            this.e = e;
            this.cur = cur;
        }

        public Node(int cur) {
            this.cur = cur;
        }
    }
}
```