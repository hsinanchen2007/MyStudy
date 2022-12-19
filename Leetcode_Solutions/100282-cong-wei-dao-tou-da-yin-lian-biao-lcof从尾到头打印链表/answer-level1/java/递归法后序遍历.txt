后序递归法放到集合重，再把集合转成数组
```
public int[] reversePrint(ListNode head) {
    List<Integer> resList = new ArrayList<>();
    add(resList, head);
    int[] res = new int[resList.size()];
    for (int i = 0; i < resList.size(); i++) {
      res[i] = resList.get(i);
    }
    return res;
  }

  private void add(List<Integer> list, ListNode listNode) {
    if (listNode == null) return;
    add(list,listNode.next);
    list.add(listNode.val);
  }
```

