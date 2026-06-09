考虑到本题目所设计的哈希表存储的键值对都是正整数，完全可以只使用Java的静态数组实现，但是实测时间和空间效率都不是很高。在静态数组的基础上添加单链表可以在较高的效率下实现，并且最终代码量并不大。
![QQ图片20200106170606.png](https://pic.leetcode-cn.com/3a0fa6d684e52dc54553f9151d64a04c7ee534d6d397f144f6a090848eb766e3-QQ%E5%9B%BE%E7%89%8720200106170606.png)

实现原理：
![绘图1.png](https://pic.leetcode-cn.com/da692f1e0ee79d462563ece9c72a8d53d108bfd5d7b088aa1d62e26a1bdb36bc-%E7%BB%98%E5%9B%BE1.png)

图中显示了存储[1=1, 2=5, 10001=1]三个键值对的哈希表，hash函数计算的哈希值作为数组的索引，数组中存储链表的虚拟头节点，当出现哈希冲突时，在链表后挂接新的节点。这样在操作哈希表时只需要判断对应hash地址是否为null，如果是null则创建虚拟头和链表头，如果已经有虚拟头则进行链表操作。使用虚拟头节点可以很方便地简化对链表的增删改操作。

- hash函数：`int hash = key % N;` N为静态数组的长度，本程序设为10000
- 底层数组：`Node[] data = new Node[N];` 
- 链表节点：每个节点中存储一个键值对，操作时保证需要键唯一
```
 private class Node {
        int key;//key唯一
        int value;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }
```

- 代码：
```
class MyHashMap {
    private final int N = 10000;//静态数组长度10000
    private Node[] data;

    /**
     * Initialize your data structure here.
     */
    public MyHashMap() {
        data = new Node[N];
    }

    /**
     * value will always be non-negative.
     */
    public void put(int key, int value) {
        int hash = hash(key);
        if (data[hash] == null) {//该hash地址没有链表节点
            data[hash] = new Node(-1, -1);//先存虚拟头
            data[hash].next = new Node(key, value);//再存实际头节点
        } else {
            Node prev = data[hash];//从虚拟头开始遍历
            while (prev.next != null) {
                if (prev.next.key == key) {
                    prev.next.value = value;//有键，更新值
                    return;
                }
                prev = prev.next;
            }
            prev.next = new Node(key, value);//没有键，添加节点
        }
    }

    /**
     * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
     */
    public int get(int key) {
        int hash = hash(key);
        if (data[hash] != null) {
            Node cur = data[hash].next;//从实际头节点开始寻找
            while (cur != null) {
                if (cur.key == key) {
                    return cur.value;//找到
                }
                cur = cur.next;
            }
        }
        return -1;//没有找到
    }

    /**
     * Removes the mapping of the specified value key if this map contains a mapping for the key
     */
    public void remove(int key) {
        int hash = hash(key);
        if (data[hash] != null) {
            Node prev = data[hash];
            while (prev.next != null) {
                //删除节点
                if (prev.next.key == key) {
                    Node delNode = prev.next;
                    prev.next = delNode.next;
                    delNode.next = null;
                    return;
                }
                prev = prev.next;
            }
        }
    }

    //哈希函数
    private int hash(int key) {
        return key % N;
    }

    //链表节点
    private class Node {
        int key;//key唯一
        int value;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

}
```
