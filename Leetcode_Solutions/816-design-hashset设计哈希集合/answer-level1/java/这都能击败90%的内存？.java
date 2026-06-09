![image.png](https://pic.leetcode-cn.com/3d99a7b47d7738098786d238977576f8e5912820cd880fda3fcd05082fa93a92-image.png)

    boolean[] a;
    /** Initialize your data structure here. */
    public MyHashSet() {
        a = new boolean[1000001];
    }
    
    public void add(int key) {
        a[key] = true;
    }
    
    public void remove(int key) {
        a[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return a[key];
    }