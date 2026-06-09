首先定义struct ListNode{}

编写Solution类
确定需要操作的节点有几个 n-m+1个
定义关键节点  pre_head、modify_list_tail、head、new_head
将头节点用指针result=head保存下来，因为head后来将发生变化
使pre_head一直是head的前一个节点
while(head&&--m){               //并且为了找到需要逆置的第一个节点，需将head指针向后推移m-1次
   pre_head=head;
   head=head->next;
}

将需要逆置的第一个节点存储在指针modify_list_tail中，防止丢失    因为在最后还要将这个节点指向后一个节点（后来的head）
modify_list_tail=head;

while(head&&chage_len){
     ListNode *next=head->next;
      链表逆置的方法
     change_len--;
}

当m不为1时，即pre_head不为空   if(pre_head){
       将pre_head于逆置后的new_head进行连接
       pre_head->next=new_head;
}
当m为1时，即从第一个节点开始逆置，pre_head为空    
else{
     result=new_head;
}

最后返回的是头节点result