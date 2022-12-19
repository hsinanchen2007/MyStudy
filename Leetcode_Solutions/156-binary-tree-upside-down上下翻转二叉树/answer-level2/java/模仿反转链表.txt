    我自己完全想不出来了各种倒不过来, 但是觉得和反转链表好像有点像, 于是照着写了一下...
    
    public TreeNode upsideDownBinaryTree(TreeNode root) {

        if(root == null || root.left == null){
            return root;
        }
        TreeNode last = upsideDownBinaryTree(root.left);
        root.left.right = root;
        root.left.left = root.right;
        root.left = null;
        root.right = null;
        return last;
    }

    206题: 反转链表写法
     public ListNode reverseList(ListNode head) {
          if(head == null || head.next == null){
              return head;
          }
          ListNode res = reverseList(head.next);
          head.next.next = head;
          head.next = null;
          return res;
    }