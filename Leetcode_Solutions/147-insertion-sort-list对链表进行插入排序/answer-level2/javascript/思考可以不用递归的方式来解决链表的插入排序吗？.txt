```javascript
    /**
     * 思考可以不用递归的方式来解决链表的插入排序吗？
     * 在原链表上不停的断链重新操作
     * pivot是基准值，总是寻找基准值的位置 pivot.next=cur.next
     * 同时找到x x.next>cur.val 因此cur.next=x.next x.next=cur
     * 此时head已经按我们需要进行了修改，返回即可
     * @param head  原链表
     * @param pivot 基准值
     * @param cur 当前需要被对比的值
     * @returns {{next}|*}
     */
    const swap=(head,pivot,cur)=>{
        let temp0=head,temp1=head;
        // 处理第一个元素就比cur.val大的情况:即插入到头部的情况
        if(temp0.val>cur.val){
            while(temp1){
                if(temp1.val===pivot){
                    break;
                }
                temp1=temp1.next;
            }
            temp1.next=cur.next;
            cur.next=temp0;
            return cur;
        }
        //处理内部情况
        while(temp0.next){
            let temp2=temp0.next;
            if(temp0.next.val>cur.val){
                // 寻找pivot所在的位置
                while(temp1){
                    if(temp1.val===pivot){
                        break;
                    }
                    temp1=temp1.next;
                }
                // 总是在修改原链表
                temp1.next=cur.next;
                cur.next=temp0.next;
                temp0.next=cur;
                return head;
            }
            temp0=temp2;
        }
    };
    /**
     * pivot是基准，可以认为是链表中最大的那个元素
     * @param llist
     * @returns {{next}|*}
     */
    const insertionSortList0=llist=>{
        if(!llist||!llist.next) return llist;
        // 指针temp
        let temp0=llist,temp1=llist.next,pivot=llist.val;
        while(temp1){
            // 提前存储下一个值，防止下面操作后temp1的值改变
            let next=temp1.next;
            if(temp1.val>=pivot){
                pivot=temp1.val;
            }else{
                temp0=swap(temp0,pivot,temp1);
            }
            temp1=next;
        }
        return temp0;
    };
```
