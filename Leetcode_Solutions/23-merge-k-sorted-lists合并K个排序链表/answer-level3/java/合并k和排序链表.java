
![image.png](https://pic.leetcode-cn.com/6fc4158fbf2096e47389c748364808cc0e8b8def409c030d83285dda23be50fd-image.png)



    public   ListNode mergeKLists(ListNode[] lists){
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        // 防止出现[[]]情况
        boolean flag = false;
        for (ListNode temp: lists) {
            if (temp != null){
                flag = true;
            }else{
                continue;
            }
            if (temp.val < min) min = temp.val;
            while(temp.next != null){temp = temp.next;};
            if (temp.val > max) max = temp.val;
        }

        if (!flag){
            return null;
        }
        // 长度
        int length = max - min + 1;

        // 计算每个数字出现的次数
        int[] arr = new int[length];
        for (ListNode temp: lists) {
            while (temp != null) {
                arr[temp.val - min] += 1;
                temp = temp.next;
            }
        }
        // 重组链表
        ListNode res = null, point = null;
        for (int i = 0; i < arr.length; i++) {
            if (res == null){
                res = new ListNode(i + min);
                arr[i] -= 1;
                point = res;
            }
            while(arr[i] > 0) {
                point.next = new ListNode(i + min);
                arr[i] -= 1;
                point = point.next;
            }
        }

        return res;

    }