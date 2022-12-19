### 解题思路
将所有元素放入ArrayList中，然后遍历去除第m个元素。
index = (m - 1) % n;
index = (index + m - 1) % list.size();

size为1的时候结束！！！

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        if (n == 0 || m == 0) {
            return -1;
        } // 参数不合法

        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(i);
        }
        int index = (m - 1) % n;
        while (list.size() > 1) {
            list.remove(index);
            index = (index + m - 1) % list.size(); 
            // 从当前位置寻找后面的第m个元素进行删除
        }

        return list.get(0);
    }
}
```