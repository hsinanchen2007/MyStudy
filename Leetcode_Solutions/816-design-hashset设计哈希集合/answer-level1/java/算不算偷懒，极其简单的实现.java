![QQ截图20200311153134.png](https://pic.leetcode-cn.com/2d0510cb38c44cecca396a4617efee9ce8d3c0195f86ee775dbfc1ba7f7dfae4-QQ%E6%88%AA%E5%9B%BE20200311153134.png)


class MyHashSet {
    boolean[] keyList;
    /** Initialize your data structure here. */
    public MyHashSet() {
        keyList = new boolean[1000001];
    }
    
    public void add(int key) {
        keyList[key] = true;
    }
    
    public void remove(int key) {
        keyList[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        if(keyList[key])
            return true;
        return false;

    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */