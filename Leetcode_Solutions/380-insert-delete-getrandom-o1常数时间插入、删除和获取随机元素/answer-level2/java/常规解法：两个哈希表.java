### 解题思路
准备两个哈希表，两个哈希表中的<键，值对>顺序相反。
删除某位置上的元素，再将这个位置的元素和最后一个元素交换以保证哈希表连续，这样才能保证getRandom()方法的随机性

### 代码

```java
class RandomizedSet {
    private HashMap<Integer, Integer> map1;
    private HashMap<Integer, Integer> map2;
    private int count;
    /** Initialize your data structure here. */
    public RandomizedSet() {
        this.map1 = new HashMap<Integer, Integer>();
        this.map2 = new HashMap<Integer, Integer>();
        this.count = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(this.map1.containsKey(val)){
            return false;
        }
        this.map1.put(val, this.count);
        this.map2.put(this.count++, val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        //先删除这个位置上的元素，再将这个位置的元素和最后一个元素交换以保证哈希表连续
        if(!this.map1.containsKey(val)){
            return false;
        }
        int tempCount = this.map1.get(val);
        this.map1.remove(val);
        this.map2.remove(tempCount);
        this.map1.put(map2.get(this.count - 1), tempCount);
        this.map2.put(tempCount, map2.get(this.count - 1));
        this.count --;
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        if(this.count == 0)
            return 0;
        return map2.get((int)(Math.random() * count));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
```