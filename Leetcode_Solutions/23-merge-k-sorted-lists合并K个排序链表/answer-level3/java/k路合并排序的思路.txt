
k路合并排序的思路
组建一个最小堆，取最小的值则为需要输出的，取出后 再去列表里面取最小的一个值放入堆里面，我这里为了方便使用java自带的sort函数，用数组来表示堆（思想差不多）
用List<ListNode> list 来记录最小的堆

```
public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        if (lists.length == 1) {
            return lists[0];
        }
        int k = lists.length;
        List<ListNode> list = new ArrayList();
        ListNode result = null, pResult = null;
        boolean first = true;

        while (true) {
            if (first) {
                for (int i = 0; i < k; i++) {
                    if (lists[i] != null) {
                        list.add(lists[i]);
                        lists[i] = lists[i].next;
                    }
                }
            }
            
            if(list.size() == 0){
                return null;
            }
            
            Collections.sort(list, new Comparator<ListNode>() {
                public int compare(ListNode o1, ListNode o2) {
                    return o1.val - o2.val;
                }
            });

            if (first) {
                result = list.get(0);
                result.next = null; 
                pResult = result;
                first = false;
            } else {
                pResult.next = list.get(0);
                pResult = pResult.next;
            }
            list.remove(0);


            ListNode minVal = null;
            int minIndex = Integer.MIN_VALUE;

            int delCount = 0;
            for (int i = 0; i < k; i++) {
                ListNode node = lists[i];
                if (node != null) {
                    if (minVal == null) {
                        minVal = node;
                        minIndex = i;
                    } else if (minVal.val > node.val) {
                        minVal = node;
                        minIndex = i;
                    }
                } else {
                    delCount++;
                }
            }
            if (minVal != null) {
                list.add(minVal);
                lists[minIndex] = lists[minIndex].next;
                // array[firstCount].next = null;
            }
            if (delCount == k) {
                break;
            }

        }
        if(list!= null && list.size()>0){
            for(ListNode iter:list){
                pResult.next = iter;
                pResult = pResult.next;
            }
        }
        return result;
    }
```
