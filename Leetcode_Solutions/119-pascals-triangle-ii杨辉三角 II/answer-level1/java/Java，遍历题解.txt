因为这题只需要返回一层的数据，所以我们也可以用上一题类似的操作，只不过每个层不通过list来区分，而是都放再一起。当新的一层的数据要放入时，旧一层的数据就要逐渐的poll出去。这样整个List链表的长度不会超过k。那么空间复杂度应该也是O(k)了吧。
```
public List<Integer> getRow(int rowIndex) {

    List<Integer> ls = new LinkedList<>();
    ls.add(1);
    if (rowIndex == 0) {
        return ls;
    } else if (rowIndex == 1) {
        ls.add(1);
        return ls;
    }

    for (int i = 2; i <= rowIndex + 1; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0) {
                ls.add(1);
            } else if (j == i - 1) {
                ((LinkedList<Integer>) ls).poll();
                ls.add(1);
            } else {
                ls.add(ls.get(1) + ls.get(0));
                ((LinkedList<Integer>) ls).poll();
            }
        }
    }

    return ls;
}
```