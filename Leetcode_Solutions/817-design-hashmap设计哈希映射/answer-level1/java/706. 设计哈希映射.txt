/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/9
 * 
 * 解题思路: 捷径一下 或者 数组加链表
 * 
 */

```
class MyHashMap {

    int[] a;
    /** Initialize your data structure here. */
    public MyHashMap() {
        a = new int[1000001];
        for(int i = 0;i < a.length;i++){
            a[i] = -1;
        }
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        a[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        return a[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        a[key]  = -1;
    }
}
```