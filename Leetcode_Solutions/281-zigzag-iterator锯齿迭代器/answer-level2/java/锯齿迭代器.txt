### 解题思路
此处撰写解题思路

### 代码

```java
public class ZigzagIterator {

    private List<Integer> list;
    private int cur=0;

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        list=new ArrayList<>();
        int i=0;
        for(;i<v1.size()&&i<v2.size();i++)
        {
            list.add(v1.get(i));
            list.add(v2.get(i));
        }
        while(i<v1.size())
            list.add(v1.get(i++));
        while(i<v2.size())
            list.add(v2.get(i++));
    }

    public int next() {
        return list.get(cur++);
    }   

    public boolean hasNext() {
        return cur!=list.size();
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */
```