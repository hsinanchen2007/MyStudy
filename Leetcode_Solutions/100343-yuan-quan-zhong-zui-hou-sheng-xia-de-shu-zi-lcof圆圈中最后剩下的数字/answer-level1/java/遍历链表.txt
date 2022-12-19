### 解题思路
使用ArrayList add remove 索引记得取余数

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        //基于ArrayList的模拟链表删除
        ArrayList<Integer> list=new ArrayList<>(n);
        for (int i=0;i<n;i++){
            list.add(i);
        }
        int idx=0;
        while (n>1){
            idx=(idx+m-1)%n;
            list.remove(idx);
            n--;
        }
        return list.get(0);
    }
}
```