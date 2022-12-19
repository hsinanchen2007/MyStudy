### 解题思路


### 代码

```java
class MyHashSet {

    /**
     * Initialize your data structure here.
     */
    int[] sets;

    public MyHashSet() {
        sets = new int[1000000];
        Arrays.fill(sets, -1);
    }

    public void add(int key) {
        sets[key] = 1;
    }

    public void remove(int key) {
        sets[key] = -1;
    }

    /**
     * Returns true if this set contains the specified element
     */
    public boolean contains(int key) {
        return sets[key] == 1;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```