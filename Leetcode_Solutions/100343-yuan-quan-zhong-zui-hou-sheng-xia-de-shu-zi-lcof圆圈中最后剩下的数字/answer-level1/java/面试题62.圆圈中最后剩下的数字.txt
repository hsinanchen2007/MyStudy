### 解题思路
用ArrayList的remove方法进行删除。

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        ArrayList list = new ArrayList();
        for (int i = 0; i < n ; i++) {
            list.add(i);
        }
        int index = 0;
        while(n > 1){
            index = (index + m - 1) % n;
            list.remove(index);
            n--;
        }
        return (int)list.get(0);
    }
}
```