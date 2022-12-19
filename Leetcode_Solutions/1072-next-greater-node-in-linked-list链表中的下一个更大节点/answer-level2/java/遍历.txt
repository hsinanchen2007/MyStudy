```
public int[] nextLargerNodes(ListNode head) {
        ArrayList<Integer> list = new ArrayList<>();
        ListNode current = head;
        while (current != null) {
            list.add(current.val);
            current = current.next;
        }
        int i = 0, j = i + 1;
        int[] result = new int[list.size()];
        while (i < list.size()) {
            j = i + 1;
            while (j < list.size()) {
                if (list.get(j) > list.get(i)) {
                    result[i] = list.get(j);
                    break;
                }
                j++;
            }
            i++;
        }
        return result;
    }
```
