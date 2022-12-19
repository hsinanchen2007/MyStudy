### 解题思路
1. 不同的动物，对应的类型数字不同，可以利用这一点，将类型数字对应数组的下标，即可存放不同动物。
2. 当遇到相同类型动物时，每只相同动物就对应相同下标，所以可以考虑以链表的方式，将相同下标的动物，挂在对应数组成员的下面，就可以存储类型相同的动物。
3. 存储时通过index记录动物进入的顺序，方便找到最老的。
4. 取出时，如果该类动物存在就直接从对应数组成员中弹出，之后维护对应链表。
5. 取出所有动物中最老的那个，需要先找到所有动物中最老的那个，也就是要遍历数组成员，找到index最小的那个，然后重复4.

### 启发
HashMap存储数据。

### 个人代码缺点
自己的实现太慢了，提交后时间在300ms左右。

### 更新日志
    新增：
        1. 添加尾指针数组，记录每个链表最后的节点，方便入队操作，运行时间大幅提高，最快能跑到95ms。

### 代码
```
class AnimalShelf {
    /**
     * 不同种类动物存放在不同的下标位置
     */
    private Node[] table;
    /**
     * 下标表示不同的种类，存储对应种类的数量
     */
    private int[] typeSize;
    /**
     * 标记
     */
    private int index;
    /**
     * 所有动物的总数
     */
    private int size;

    /**
     * 新增: 尾指针数组
     */
    private Node[] tail;

    public AnimalShelf() {
        // 猫和狗两种，两者类型id最大值为1，所以初始化为2。
        table = new Node[2];
        typeSize = new int[table.length];
        // 新增
        tail = new Node[table.length];
    }

    public void enqueue(int[] animal) {
        // 收容所最大为20000
        if (size >= 20000 || animal == null || animal.length == 0)
            return;
        // animal[0]为动物id，animal[1]种类
        int type = animal[1];
// 删除 ->       Node p;
        // 该数组成员上没有存东西，则放在数组上。
// 删除 -> if ((p = table[type]) == null) {
        // 新增
        if (table[type] == null) {
            table[type] = new Node(animal, index++, null);
            // 新增
            tail[type] = table[type];
        } else {
            // 有东西则挂在该数组成员的最后面（保持先进的动物在前面）
// 删除 ->    while (p.next != null) {
// 删除 ->         p = p.next;
// 删除 ->    }
// 删除 ->   p.next = new Node(animal, index++, null);
            // 新增
            tail[type].next = new Node(animal, index++, null);
            // 新增
            tail[type] = tail[type].next;
        }
        typeSize[type]++;
        size++;
    }

    public int[] dequeueAny() {
        int minIndex = -1;
        int minType = -1;
        for (int i = 0; i < typeSize.length; i++) {
            // 对应的动物数量必须大于零，即该种类有动物才能比较。
            if (typeSize[i] > 0) {
                if (minIndex < 0) {
                    // 初始化minType
                    minIndex = table[i].index;
                    minType = i;
                } else {
                    // 数组成员为对应种类链表的头结点，也是最早进入的。
                    // 找出数组中index最小的那个，就找到了对应的最早进入的动物类型
                    if (minIndex > table[i].index) {
                        minIndex = table[i].index;
                        minType = i;
                    }
                }
            }
        }
        return dequeue(minType);
    }

    public int[] dequeueDog() {
        return dequeue(1);
    }

    public int[] dequeueCat() {
        return dequeue(0);
    }

    private int[] dequeue(int type) {
        // 要判断(type != 0 && type != 1)是因为要防止取出0、1之外的类型，题目限定为只有0、1，如果不止猫狗这两类，就可以删除这个判断。
        if (type < 0 || typeSize[type] == 0 || (type != 0 && type != 1)) {
            return new int[]{-1, -1};
        }
        Node oldestAnimal = table[type];
        table[type] = table[type].next;
        typeSize[type]--;
        size--;
        return oldestAnimal.animal;
    }

    private class Node {
        int[] animal;
        int index;
        Node next;

        Node(int[] animal, int index, Node next) {
            this.animal = animal;
            this.index = index;
            this.next = next;
        }
    }
}
```
