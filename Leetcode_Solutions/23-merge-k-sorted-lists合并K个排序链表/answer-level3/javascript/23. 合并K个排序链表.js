# 链表转数组
遍历所有节点将节点值提取到数组中，然后对数组排序，遍历数组将数组内容重新转化为链表
```
var mergeKLists = function(lists) {
    let len  = lists.length;
    if(len == 0) return null;
    if(len == 1) return lists[0];
    let arr = new Array();
    for(let i = 0;i<len;i++){
        let temp = lists[i];
        while(temp){
            arr.push(temp.val);
            temp = temp.next;
        }
    }
    arr.sort((a,b)=>a-b);
    let heap = new ListNode();
    let cur = heap;
    for(let i = 0,len = arr.length;i<len;i++){
        let node = new ListNode(arr[i]);
        cur.next = node;
        cur = cur.next;
    }
    return heap.next;
};
```
- 遍历所有节点时间复杂度O(n),申请数组空间，空间复杂度O(n)
- 对数组进行排序，JS中sort算法喂快排，时间复杂度为O(logn)
- 数组转化为链表，时间复杂度为O(n)，空间复杂度为O(n)

# 链表逐一进行合并
```
var mergeKLists = function(lists) {
    let len  = lists.length;
    if(len == 0) return null;
    if(len == 1) return lists[0];
    let heap = new ListNode();
    heap.next = lists[0];
    for(let i = 1;i<len;i++){
        let cur1 = heap.next;
        let cur2 = lists[i];
        let origh = heap;
        while(cur1 != null&&cur2 != null){
            if(cur1.val>= cur2.val) {
                origh.next = cur2;
                cur2 = cur2.next;
            }else{
                origh.next = cur1;
                cur1 = cur1.next;
            }
            origh = origh.next;
        }
        if(cur1) origh.next = cur1;
        if(cur2) origh.next = cur2;
    }
    return heap.next;
};
```
- 需要遍历整个数组k趟，每趟遍历n<=N个链表节点，时间复杂度为O(kN)，所有操作基于原链表节点，空间复杂度为O(1)
