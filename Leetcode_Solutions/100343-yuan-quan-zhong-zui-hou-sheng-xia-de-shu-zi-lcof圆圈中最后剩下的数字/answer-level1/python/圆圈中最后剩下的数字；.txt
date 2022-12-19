### 解题思路
将数字（0~n-1）放入list中，更新size为每次删除了第m个元素后的list的长度，第m个数可以通过m + k -1 对 size 取余获得,该余数记为k, 相当于将每次第m个元素之后剩余的元素循环右移。

### 代码

```java []
class Solution {
     public int lastRemaining(int n, int m) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(i);
        }
        int size = n;
        int k = 0;
        while (size != 1){
            k = (m + k - 1) % size;  
            list.remove(k);
            size--;
        }
        return list.get(0);
    }
}
```
```python []
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        list = []
        k = 0
        for i in range(n):
            list.append(i)
        while(n != 1):
            k = (m + k -1) % n
            del list[k]
            n -= 1
        return list[0]        
         
```
