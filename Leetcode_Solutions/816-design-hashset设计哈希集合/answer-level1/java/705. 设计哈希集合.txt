/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/9
 *
 * 解题思路: 这算走捷径么  或者数组+链表实现 链表用来实现偏移
 *
 */
```
public class leetcode705 {

    int[] hash;
    /** Initialize your data structure here. */
    public leetcode705() {
        hash = new int[1000001];
    }

    public void add(int key) {
        hash[key] = 1;
    }

    public void remove(int key) {
        hash[key] = 0;
    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        if(hash[key] == 1){
            return true;
        }else {
            return false;
        }
    }


}
```