### 解题思路
方法一、将两个链表的值分别存入两个数组中，遍历两个数组，遇到相同的值则返回该值，提交通过
但是我觉得这个方法是有问题的，在测试用例中
[4,1,8,4,5]
[5,0,1,8,4,5]
第一个链表有两个4，在遇到第一个4时，他就和第二个链表中的4相等，这个时候就满足判断条件，但事实上应该是第二个4才是正确的交点，这个该如何解释

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    var arrA=[];
    var arrB=[];
    while(headA!=null){
        arrA.push(headA);
        headA=headA.next;
    };
    while(headB!=null){
        arrB.push(headB);
        headB=headB.next;
    };
    for(var i=0;i<arrA.length;i++){
        for(var j=0;j<arrB.length;j++){
            if(arrA[i]===arrB[j]){
                return arrB[j];
            }
        }
    }
    return null;
};

```
方法二、哈希map
使用map.set(key,value)建立一个哈希表，使用map.has(key)来判断哈希表中是否有该值，如果有即返回该值
```
var getIntersectionNode = function(headA, headB) {
    var map = new Map();
    while(headA){
        map.set(headA,true);
        headA=headA.next;
    }
    while(headB){
       if(map.has(headB)){
           return headB;
       } else{
           headB=headB.next;
       }
    }
    return null;
};
```
方法三、1.先找两条链长的差值 2.除掉差值，两条链表在同一起点出发 3.若相遇，则返回；否则返回空
方法四、双指针法