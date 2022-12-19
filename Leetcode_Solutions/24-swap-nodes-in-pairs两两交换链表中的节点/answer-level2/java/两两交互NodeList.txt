
```
public Class ListNodeDemo{
    publc NodeList swapNodeList(NodeList head){
        if(head==null||head.next==null){
            return head
        }
        NodeList  next = head.next;
        head.next = swapodeList(next.next);
        next.next = head;
        return next;
   }

}
```
