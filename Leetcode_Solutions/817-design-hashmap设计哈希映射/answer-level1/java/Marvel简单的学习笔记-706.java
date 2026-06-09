### 线性探测法实现哈希表
复习一遍线性探测法，思路简单，具体实现看完下面的代码和注释应该很容易理解。
线性探测法使用了一对平行数组来存储键值对，利用数组的空位来解决冲突问题。顾名思义，当遇到冲突时，线性往后检测数组下一个位置，直到遇到空位，将新的键值对存储。查找也是一样，如果遇到空位还没有找到，说明不存在该键值对。总的来说，数组的空位就是查找结束的标志。
此外，有一点需要注意，题目提到所有数据的值都大于等于1，实际不然，测试样例中会出现值为0的数据，要留意。

### 代码

```java
class MyHashMap {
    private static final int CAPACITY = 4;
    private int m;
    private int n;
    private int[] keys;
    private int[] vals;

    /** 
     * 无参构造函数 
     */
    public MyHashMap() {
        this(CAPACITY);
    }

    /**
     * 有参构造函数
     * @param 散列表的大小，即键值数组的长度
     */
    public MyHashMap(int cap) {
        m = cap;
        n = 0;
        keys = new int[cap];
        vals = new int[cap];
        for(int i = 0; i < m; i++)
            keys[i] = -1;//键数组元素为-1，代表该位置为空
    }

    /**
     * 动态调整数组的大小
     * @param 散列表调整后的大小
     */
    private void resize(int cap) {
        MyHashMap temp = new MyHashMap(cap);
        for(int i = 0; i < m; i++)
            if(keys[i] != -1)  temp.put(keys[i], vals[i]);
        m = temp.m;
        n = temp.n;
        keys = temp.keys;
        vals = temp.vals;
    }

    /**
     * 散列函数
     * @return 键的散列值
     */
    private int hash(int key) {
        return key % m; 
    }
    
    /** 
     * 插入键值对
     * @param value为非负 
     */
    public void put(int key, int value) {
        if(n >= m/2)    resize(2 * m);//散列表小了，动态调整大小
        int i;
        for(i = hash(key); keys[i] != -1; i = (i + 1)  % m)
        {
            if(keys[i] == key)
            {
                vals[i] = value;
                return;
            }
        }
        keys[i] = key;
        vals[i] = value;
        n++;
    }
    
    /** 
     * 返回给定键对应的值，若键不存在则返回-1 
     */
    public int get(int key) {
        for(int i = hash(key); keys[i] != -1; i = (i + 1) % m)
            if(keys[i] == key)  return vals[i];
        return -1;
    }
    
    /** 
     * 删除键值对 
     */
    public void remove(int key) {
        if(get(key) == -1)  return;
        int i = hash(key);
        while(keys[i] != key)
            i = (i + 1) % m;
        keys[i] = -1;//删除
        vals[i] = -1;
        n--;
        i = (i + 1) % m;
        while(keys[i] != -1)
        {
            int tempKey = keys[i];
            int tempVal = vals[i];
            keys[i] = -1;
            vals[i] = -1;
            n--;
            put(tempKey, tempVal);
            i = (i + 1) % m;
        }
        if(n > 0 && n <= m/8)    resize(m / 2);//散列表大了，动态调整大小
    }
}
```