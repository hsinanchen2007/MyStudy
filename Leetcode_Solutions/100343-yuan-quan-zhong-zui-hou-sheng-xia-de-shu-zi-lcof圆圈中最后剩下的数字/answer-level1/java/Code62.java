### 解题思路
这是一道数学题……，尼玛，写个链表超时了。

### 代码

```java
class Solution {

    public int lastRemaining(int n, int m) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(i);
        }

        int fromIndex = 0;
        while(arr.size() > 1) {
            fromIndex = ((m - 1) + fromIndex) % arr.size();
            arr.remove(fromIndex);

        }

        return arr.get(0);
    }
}
```