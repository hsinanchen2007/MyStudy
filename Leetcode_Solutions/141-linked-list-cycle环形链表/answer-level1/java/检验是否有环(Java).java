```
public boolean hasCycle(ListNode head) {
        boolean flag=false;
        ListNode slow=head;
        ListNode fast=head.next;
        if(head==null){//为空直接返回
            return flag;
        }
        while(slow!=null&&fast!=null){
            if(slow==fast){//快慢指针相撞，说明存在环
                flag=true;
                break;
            }else{//不相撞的情况下，让慢指针向后移动一，让快指针向后移动两
                if(fast.next==null||fast.next.next==null){//如果不存在环，快指针的next或next.next先为null;
                    break;
                }else{
                    slow=slow.next;
                    fast=fast.next.next;
                }
            }
        }
        return flag;
        }
```


![TIM截图20191116115033.png](https://pic.leetcode-cn.com/baea8895816686ac7022495809726d40d3f4035f631b6a2e441ba1412a00115f-TIM%E6%88%AA%E5%9B%BE20191116115033.png)
