### 解题思路
使用两张hash表

map1 存 (val，索引)
map2 存 (索引，val)

getRandom 等概率随机返回： map2[(rand() % size)]

注意：因为删除操作会把原来连续的索引值变得不连续，中间有空缺，此时无法使用rand()在常数时间获取到有效值  
     需要在删除操作中把删除后留下的空缺填补上

### 代码

```cpp
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        // m_map1.reserve(8192);
        // m_map2.reserve(8192);
        m_size = 0;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        if (m_map1.find(val) != m_map1.end()) //已存在
        {
            return false;
        }

        m_map1[val] = m_size;
        m_map2[m_size] = val;

        ++m_size;

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        if (m_map1.find(val) == m_map1.end()) //不存在
        {
            return false;
        }
        
        //使用最后一条记录填补被删除的空缺
        //将m_map1的(last_val, last_index)改为(last_val, index)
        int index = m_map1[val];
        int last_index = --m_size;
        int last_val = m_map2[last_index];
        
        m_map1[last_val] = index; //注意：先改 后删
        m_map1.erase(val); //删除(val, index)

        m_map2[index] = last_val; //将m_map2的(index, val)改为(index, last_val) 
        m_map2.erase(last_index); //删除(last_index, last_val)

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        //如果为空呢？？ 这里不考虑
        return m_map2[rand() % m_size];
    }

private:
    unordered_map<int, int> m_map1;
    unordered_map<int, int> m_map2;
    int m_size;

};
```