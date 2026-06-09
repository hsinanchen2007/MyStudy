&emsp;&emsp;估计大家也看过官方的题解了。这里，我主要谈一下自己写的这个归并排序算法的时间复杂度是如何计算出来的。不说废话了，直接上代码。击败99.2%

```javascript
function partition(lists) {
    switch(lists.length) {
        case 0:
            return null;
        case 1:
            return lists[0];
        case 2:
            return merge2Lists(lists[0], lists[1]);
        default: 
            let mid = lists.length >> 1;
            return merge2Lists(partition(lists.slice(0, mid)), 
                            partition(lists.slice(mid, lists.length))); 
    }
}

function merge2Lists(l0, l1) {
    let p0 = l0, 
        p1 = l1, 
        c = new ListNode(null),
        pc = c;
    while(p0 || p1) {
        if (p0 && p1) {
            if(p0.val < p1.val) {
                pc.next = p0;
                p0 = p0.next;
            } else {
                pc.next = p1;
                p1 = p1.next;
            }
        } else if (p0) {
            pc.next = p0;
            break;
        } else if (p1) {
            pc.next = p1;
            break;
        }
        pc = pc.next;
    }
    return c.next;
}

var mergeKLists = function(lists) {
    return partition(lists);
};
```

&emsp;&emsp;从代码中可以看出，我主要用了两个函数实现归并排序，第一个函数Partition用于2分数组Lists，第二个函数merge2Lists用于合并并排序两个链表。假设Lists的长度为L，那么Partition的时间开销就是二分法得到的Log(L)，而merge2Lists的时间开销应当是min(m1, m2)其中m1和m2为排序的两个链表的长度。

综上，时间复杂度等于Partition的时间开销乘以merge2Lists的时间开销，即O(min(m1, m2)logL) <= O(MlogL)其中M为链表数组中最长的链表的长度。
