![QQ图片20200226181457.png](https://pic.leetcode-cn.com/4b1143d5552cb584b54cc17fd2d6e8ba536b162c81cb3ba65960ed1e335b43c5-QQ%E5%9B%BE%E7%89%8720200226181457.png)

public static ListNode swapPairs(ListNode head) {
        if(head == null) return null;
        if(head.next == null) return head;
        ListNode arr = head;
        head = head.next;
        ArrayList<ListNode> list = new ArrayList<>();
        while(arr != null){
            list.add(arr);
            arr = arr.next;
        }
        for (int i = 0; i < list.size(); i ++){
            if(i % 2 == 0 && i + 3 < list.size()){
                list.get(i).next = list.get(i + 3);
            }else if (i % 2 == 1){
                list.get(i).next = list.get(i - 1);
            }else if (i + 2 < list.size()){
                list.get(i).next = list.get(i + 2);
            }else{
                list.get(i).next = null;
            }
        }
        return head;
    }