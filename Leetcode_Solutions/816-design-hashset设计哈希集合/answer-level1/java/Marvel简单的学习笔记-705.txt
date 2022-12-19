## 重温线性探测法和拉链法

### 线性探测法
使用一个数组存放值，利用数组中的空位解决冲突，即当遇到冲突时，检测数组的下一个位置，这样会产生三种结果：
1. 被其他值占用了
2. 命中，该位置的值就是待查找的值
3. 遇到一个空位，即未命中

遇到情况1时，我们需要继续往后查找；
遇到情况2时，命中，可以返回。
遇到情况3时，未命中，即散列表中没有待查找的值，此时可以返回false，或在此位置上添加该值。

这样不断地线性往后查找空位，把空位作为查找结束的标志，这就是线性探测法。

难点在于删除元素，不能直接删除某一元素，因为待删除元素的后面可能还有别的元素，这些别的元素所占有的位置，可能是基于前面已被占用的位置往后探测找到的，如果前面某一元素被删了，这些后面的元素就无法基于前面被占用的位置往后探测到了，即无法正常查找了。
因此，删除操作在删除元素的同时，需要把删除元素后面的连续元素重新插入到散列表中。

代码：

```java
class MyHashSet {
    private static final int capacity = 4;//数组默认大小
    private int m;//数组大小，即散列表大小
    private int n;//散列表中key的数目
    private Integer[] keys;//数组

    /** Initialize your data structure here. */
    //无参构造函数
    public MyHashSet() {
        this(capacity);
    }

    //指定散列表大小的构造函数
    public MyHashSet(int cap) {
        m = cap;
        n = 0;
        keys = new Integer[m];
    }

    //散列函数
    private int hash(int key) {
        return key % m;
    }

    //动态调整散列表的大小
    private void resize(int cap) {
        MyHashSet temp = new MyHashSet(cap);
        for(int i = 0; i < m; i++)
            if(keys[i] != null) 
                temp.add(keys[i]);
        keys = temp.keys;
        m = temp.m;
    }
    
    //添加元素
    public void add(int key) {
        if(n >= m/2)    resize(2 * m);
        int i;
        for(i = hash(key); keys[i] != null; i = (i + 1) % m)
        {
            if(keys[i] == key)  return;
        }
        keys[i] = key;
        n++;
    }
    
    //删除元素
    public void remove(int key) {
        if(!contains(key))  return;
        int i = hash(key);
        while(keys[i] != key)
        {
            i = (i+1) % m;
        }
        keys[i] = null;
        n--;
        i = (i+1) % m;
        while(keys[i] != null)
        {
            int temp = keys[i];
            keys[i] = null;
            n--;
            add(temp);
            i = (i+1) % m;
        }
        if(n > 0 && n <= m/8)    resize(m / 2);
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        for(int i = hash(key); keys[i] != null; i = (i+1) % m)
        {
            if(keys[i] == key)  return true;
        }
        return false;
    }
}
```

### 拉链法
使用一个大小为m的数组，数组的每个元素都是一条链表，所有散列到数组同一下标的元素都存储在对应的链表中，以此来解决冲突。当冲突碰撞的元素越来越多时，链表中的元素就会变多，链表也就会变长，因此需要动态调整数组的大小，即增加链表的数量，使链表尽可能短，从而保证高效的查找。
根据散列值找到对应下标的链表，沿着链表查找给定的键。每条链表的平均长度（即每条链表平均含有的元素个数）在2到8为宜。

代码：

```java
class MyHashSet {
    private static final int CAPACITY = 4;//链表默认数量
    private int m;//链表数量，即散列表大小
    private int n;//key数量
    private LinkedList<Integer>[] list;

    /** Initialize your data structure here. */
    public MyHashSet() {
        this(CAPACITY);
    }

    public MyHashSet(int cap) {
        m = cap;
        n = 0;
        list = (LinkedList<Integer>[]) new LinkedList[m];
        for(int i = 0; i < m; i++)
            list[i] = new LinkedList<Integer>();
    }

    private int hash(int key) {
        return key % m;
    }

    //动态调整数组大小
    private void resize(int cap) {
        MyHashSet temp = new MyHashSet(cap);
        for(int i = 0; i < m; i++)
        {
            for(int j : list[i])
                temp.add(j);
        }
        this.m = temp.m;
        this.n = temp.n;
        this.list = temp.list;
    }
    
    public void add(int key) {
        if(n >= 8*m)    resize(2 * m);
        if(!contains(key))
        {
            n++;
            int i = hash(key);
            list[i].add(key);
        }
    }
    
    public void remove(int key) {
        if(contains(key))
        {
            n--;
            int i = hash(key);
            list[i].remove(new Integer(key));
        }
        if(m > CAPACITY && n <= 2*m)    resize(m / 2);
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        int i = hash(key);
        return list[i].contains(key);
    }
}
```