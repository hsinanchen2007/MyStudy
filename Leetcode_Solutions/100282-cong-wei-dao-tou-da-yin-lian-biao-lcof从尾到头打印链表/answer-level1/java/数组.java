    //时间复杂度O(n)空间复杂度O(1)
    //先遍历出数组长度
    //从头结点遍历，放到数组最后一位
    //一次类推，链表往后走，数组向前走

    class Solution {
        public int[] reversePrint(ListNode head) {
            int size = 0;
            ListNode node = head;
            while(node != null){
                size++;
                node = node.next;
            }
            int[] result = new int[size];
            while(head != null){
                result[--size] = head.val;
                head = head.next;
            }
            return result;
        }
    }

![f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg](https://pic.leetcode-cn.com/cb4f12db78daa092d48d29c60e3aafa75296a9eeb52aff0b5dee24b8d9dce4ba-f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg)

    //也可以用递归或者Stack

