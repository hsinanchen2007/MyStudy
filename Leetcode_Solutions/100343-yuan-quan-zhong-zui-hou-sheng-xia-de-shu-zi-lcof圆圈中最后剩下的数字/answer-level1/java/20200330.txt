### 解题思路
用ArrayList 模拟数据的删除过程，尝试过用数组模拟但是数组不方便进行删除操作，会超时

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            tmp.add(i);
        }
        int index = 0;
        while (n > 1) {
            index = (index + m - 1) % n;
            tmp.remove(index);
            n--;
        }
        return tmp.get(0);


    }
}
```