# 思路
1. indexList 若是下一个元素比它大则存储下一个元素下标值，否则存0；在后续再次遍历填充结果数组时，会对于所存下标为0的位置进行更新；
2. headList 按顺序存储原链表的val值
3. 比如indexList.get(6)值为8，表示headList(6)的下一个更大节点值为headList(8)。

# 代码
```
public static int[] nextLargerNodes(ListNode head) {

    List<Integer> indexList = new ArrayList<>();
    List<Integer> headList = new ArrayList<>();
    ListNode p = head;
    int count = 0;
    while (p != null) {
        count++;
        if (p.next != null && p.next.val > p.val) {
            indexList.add(count);
        } else {
            indexList.add(0);
        }
        headList.add(p.val);
        p = p.next;
    }
    int[] rstArray = new int[count];
    int index = 0, j = 0;
    // 从倒数第二个元素开始，反向遍历并填充结果数组
    for (int i = count - 2; i >= 0; i--) {
        index = indexList.get(i);
        if (index != 0) {
            rstArray[i] = headList.get(index);
            j = index;
        } else {
            while (j != 0 && headList.get(j) <= headList.get(i)) {
                // 以下标链式的方式，找到第一个比当前元素大的值。
                j = indexList.get(j);
            }
            // 将比当前元素大的值的下标记录
            indexList.set(i, j);
            rstArray[i] = (j == 0) ? 0 : headList.get(j);
        }
    }
    indexList.clear();
    headList.clear();
    return rstArray;
}
```

# 总结
1. 时间复杂度 O(n)
- 对链表遍历一次;
- 对indexList遍历一次,遍历indexList时可能会触发对下标链的查找。考虑极端情况，链表为[n,1,2,3,...,n-1]，遍历到i=0时，查找下标链长度n-1,其余查找长度1，总查找长度2n-2,时间复杂度O(n).
2. 空间复杂度 O(n)
- 两个大小为n的列表，一个大小为n的数组。