题目数据不对
["MyHashMap","remove","put","put","put","put","put","put","get","put","put"]
[[],[2],[3,11],[4,13],[15,6],[6,15],[8,8],[11,0],[11],[1,10],[12,14]]

又说数据 【1，1e6】  居然有【11，0】

# 数组取巧
看了数据题目范围  可以开数组
```
class MyHashMap {
public:
    //关键是删除O1，查找O1 发现能开1e6的数组
    const static int N = 1e6 + 100;
    int hash[N];
    // int *hash;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        memset(hash, -1, sizeof(hash));
        //hash = new int *hash;
        //memset(hash, -1, sizeof(int) * N);//0、-1可以memset
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hash[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {        
        return hash[key];
        //return  (hash[key] == 0)? -1 : hash[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hash[key] = -1;
        //hash[key] = 0;
    }
};
```

但题目设计出来 本意肯定并不是上面这样子 
**哈希表的基本思想都是先开一个大数组，然后用某种哈希函数将key映射到数组的下标空间。
不同算法的区别在于如何处理下标冲突，即当两个不同的key被映射到同一下标时，该怎么办。**

# 哈希函数设计
key % 一个素数N
这里操作数1e4  我们取N = 20011

# 拉链法（大数据）
通过hash函数，把各种key值分类成（这里就是  %一个素数  实现）  几个链
然后就是通过寻找有没有对应的key值，有就返回位置，修改，没有就push_back
链表删除O1
相比数组这种，空间省太多了，而且由于分类的好，一般就是N稍微是操作数的两倍
那期望查询O1复杂度，因为每条链都比较短。。。

```
class MyHashMap {
public:
    //拉链法，比用数组 省很多空间，利用hash函数 key%N  即最多N条链，相当于分类，这样其实如果分类得好，每条链都很短的
    const static int N = 20011; //%一个素数 比较好
    vector<list<pair<int, int>>> hash;
    /** Initialize your data structure here. */
    MyHashMap() {
        hash = vector<list<pair<int, int>>>(N);
    }
    
    list<pair<int, int>>::iterator find (int key) {
        int k = key % N; //定位到 k链
        auto it = hash[k].begin();
        for (; it != hash[k].end(); it++) {
            if (it->first == key)//存在
                break;
        }
        return it;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = key % N;
        auto it = find(key);
        //存在两种情况，一就是it就是k链的end()  即还不存在  二就是找到了
        if (it != hash[k].end())
            it->second = value;
        else 
            hash[k].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int k = key % N;
        auto it = find(key);
        //其实对于链表，我找到了it 是可以O1删除的，不过我们也可以标记它 
        if (it == hash[k].end())
            return -1;
        return it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k = key % N;
        auto it = find(key);
        if (it != hash[k].end())
            hash[k].erase(it);
    }
};
```

# 开放寻址法（小数据）
引用个例子：上厕所。。。。。
在进行坑位选择时，顾客对所有的坑位有一个喜好（这里可以看成hash函数的值），相当于每个人有喜欢的一类，尽量选择最喜欢的坑位，检查里面是否有人，然后进行蹲坑，这就是进行insert操作。
而search，可以认为是有人来厕所找人，他知道被找人的喜好，然后按照被找人的喜好，依次查找，如果找到某个人，可以返回位置信息。
如果按顺序 【居然】找到一个“干净”的坑位，就返回要找的人没在厕所。
你可能会觉得，可能找的人还后面一点，或者他已经走了，即被remove了。
先看下这个例子，通过哈希函数，我们分了类，那其实就存在 多个人 喜欢 某一种类别的坑位，比如3  6  30  % 3 都 == 0

**约定：人上完 不冲厕所；找到干净位置就说明这个人不在厕所，要么找得到人
“干净”的坑位可以理解是没有人使用过该坑位。**
假设把3、6、30  insert 到哈希表，这时候remove 6
这时候查询30有无，很明显，30还在，但如果我们remove 6的时候，比如6离开厕所时，他冲厕所了，他位置是干净的，那当我查询的时候，就会停在这里，从而说没有30，这明显不对。

*所以 这就是 为什么约定 不冲厕所的原因，这样就会继续往后找，从而找到30
可以发现，开放寻址法浪费空间，如果很多remove操作就会造成空间的浪费，但我们又无法利用上，因为每个人上厕所的时间不同，离开的时刻也未知的。*
```
class MyHashMap {
public:
    const static int N = 20011;
    int hash_key[N], hash_value[N];
    
    /** Initialize your data structure here. */
    MyHashMap() {
        memset(hash_key, -1, sizeof(hash_key));
    }
    
    int find(int key) {
        int k = key % N;
        while (hash_key[k] != key && hash_key[k] != -1) {//如果找到退出
            if (++k == N)//找到尾了 就从头开始，因为中间开始的，空间开大了，操作数的几倍 肯定够空间
                k = 0;
        }
        return k;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = find(key);
        hash_key[k] = key;
        hash_value[k] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int k = find(key);
        if (hash_key[k] == -1)
            return -1;
        return hash_value[k];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k = find(key);
        if (hash_key[k] != -1)
            hash_key[k] = -2;
    }
};
```


# 总结：一般都采取 拉链法，链表O1删除，指针指一下就好
