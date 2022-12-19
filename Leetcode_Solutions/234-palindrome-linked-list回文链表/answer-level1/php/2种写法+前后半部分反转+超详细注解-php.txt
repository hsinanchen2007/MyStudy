# **写法一：**

     function isPalindrome($head) {
        if($head == null ||$head->next == null) 
            return true;                   //若链表为空或只有一个元素
        $slow = $head;                     //定义慢指针；
        $fast = $head;                     //定义快指针；
        $current = null;                   //指向当前需要反转的元素；
        $head2 = null;                     //记录反转后的头元素；

        while($fast != null && $fast->next != null){
            $current = $slow;              //先将要反转的元素赋值给current；
            $slow = $slow->next;           //慢指针遍历链表；
            $fast = $fast->next->next;     //快指针遍历链表；

            //边遍历边反转前半部分已经遍历的元素；
            $current->next = $head2;       //反转当前元素，指向反转链表head2；
            $head2 = $current;             //反转链表头元素向后移位到当前元素，准备下一次反转；
        }

        //准备比较链表head2和链表head剩下部分，即slow后边的部分，此时slow已经在链表head中位数。
        if($fast)                          //若head为奇数链表，此时fast指向最后一个元素绝逼不会空；
            $slow = $slow->next;           //slow需向后移一位取链表正中间的数；

        while($slow != null) {             //遍历两个链表元素并进行比较；
            if($slow->val != $head2->val)  //比较元素的值
                    return false;
            $slow = $slow->next;           //指针向后一位
            $head2 = $head2->next;         //准备下一轮比较
        }
        return true;
     } 

# **写法二：**

     function isPalindrome($head){
        $fast = $head;                          //设定快指针；
        $slow = $head;                          //设定慢指针；
        //先利用快慢指针遍历链表，快指针到达终点最后一个元素时，使慢指针指向中点；
        while($fast !== null && $fast->next !== null){
            $fast = $fast->next->next;          //走2步；
            $slow = $slow->next;                //走1步；
        }

        //此时slow已到达中点；反转后半部分
        $reveredList = null;                   //定义空指针，用于存放反转链表，指向头元素；
        $tmpCurrent = $slow->next;             //定义当前需要反转的元素，反转后半部分；
        while($tmpCurrent !== null){           //当当前的元素为空时退出；
            $next = $tmpCurrent->next;         //先将下一个要反转的元素赋值给next；
            $tmpCurrent->next = $reveredList;  //实现当前元素的next指针反转过来指向reveredList头元素；
            $reveredList =$tmpCurrent;         //reveredList向后移动一位指向最新反转的元素，准备下一次反转；
            $tmpCurrent = $next;               //把当前需要反转指针向后移动一位，指向下一位需要反转的元素；
           
        } 
        //遍历链表比较
        $h = $head->next;                      //准备好原始的链表
        while($reveredList !== null){          //当已经反转好的链表最后元素为空
            if ($reveredList->val != $h->val) {//比较元素的值
                return false;
            }
            $h = $h->next;                     //向后移动一位
            $reveredList = $reveredList->next; //准备比较下一位元素
        }
        return true;
     }