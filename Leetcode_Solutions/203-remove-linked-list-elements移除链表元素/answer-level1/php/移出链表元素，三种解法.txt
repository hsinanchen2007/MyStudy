删除链表中等于给定值 val 的所有节点
- 使用递归
```
function removeElements($head, $val) {
       if($head==null){
              return null;
          }
        $head->next=$this->removeElements($head->next,$val);
        return  $head->val==$val?$head->next:$head;
}
```
- 不使用递归
```
class Solution {

    /**
     * @param ListNode $head
     * @param Integer $val
     * @return ListNode
     */
    function removeElements($head, $val) {
    
        while($head !=null && $head->val == $val){
            $head=$head->next;
        }
      
        if($head==null){
            return null;
        }
        $prev=$head;
        while($prev->next != null){
            if($prev->next->val==$val){
                $delNode =$prev->next;
                $prev->next=$delNode->next;
                $delNode->next=null;
}
            else{
                $prev=$prev->next;
            }
            
        }
        return $head;
    }
}
```

- 使用虚拟头结点
```
    function removeElements($head, $val) {
        $dummyhead=new ListNode(0);
        $dummyhead->next=$head;
        
        $prev=$dummyhead;
        while($prev->next != null){
            if($prev->next->val==$val){
                $prev->next=$prev->next->next;
}
            else{
                $prev=$prev->next;
            }
            
        }
        return $dummyhead->next;
    }
```