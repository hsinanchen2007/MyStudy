报错：Line 70: Char 15: runtime error: member access within misaligned address 0x7f621ba06de2 for type 'struct ListNode', which requires 8 byte alignment (ListNode.c)
0x7f621ba06de2: note: pointer points here
解决方法：在创建一个新节点后将节点的指针域赋值为NULL