运行效率可观(1ms)，递归通病，空间消耗较大。
```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
		int n=k;
		ListNode p=head,end=null;
		while(p!=null&&n!=0){
			end=p;
			p=p.next;
			n--;
		}
		if(n!=0)return head;//递归终结条件
		end.next=reverseKGroup(end.next, k);//调用递归函数
		while(head!=end){//翻转k个结点
			p=head;
			head=head.next;
			p.next=end.next;
			end.next=p;
		}
		return end;//翻转后尾结点变为头结点
    }
}
```
希望能帮助到您！