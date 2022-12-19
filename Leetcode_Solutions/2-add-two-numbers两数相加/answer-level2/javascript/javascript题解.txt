148ms  393MB
完成的第一版结果，回头检查代码，两数组相加后可直接生成链表了，无需存入临时数组在转换为链表，后续再调整。

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let res = []; // 相加后的结果
    let l1Arr = []; // l1转数组
    let l2Arr = []; // l2转数组
    let largeTarget; // 较长的链表
    let smallTarget; // 较短的链表

    // 链表转数组
    while(l1 && typeof l1.val === 'number'){
        l1Arr.push(l1.val);
        l1 = l1.next;
    }
    while(l2 && typeof l2.val === 'number'){
        l2Arr.push(l2.val);
        l2 = l2.next;
    }

    // 找到较长的数组和较短的数组
    largeTarget = l1Arr.length > l2Arr.length ? l1Arr : l2Arr;
    smallTarget = largeTarget === l1Arr ? l2Arr : l1Arr;
    
    let carryFlag = false; // 进位标志

    // 两数组相加，并将结果存入新数组中
    for(let i = 0; i < largeTarget.length; i++){
        let smallTemp = smallTarget.length > i ? +smallTarget[i] : 0;
        let temp = +largeTarget[i] + smallTemp;
        let calc = (temp % 10) + (carryFlag ? 1 : 0);
        if(calc < 10){
            res.unshift((temp % 10) + (carryFlag ? 1 : 0));   
            carryFlag = false;
        } else {
            res.unshift(0);   
            temp = 10;
        }
        
        if(temp >= 10){
            if(i === largeTarget.length - 1){
                res.unshift(1);
            } else {
                carryFlag = true;
            }
        }
    }
    
    
    // 结果数组转链表
    let resList;
    let temp;
    for(let i = res.length - 1; i >= 0; i --){
        if(i === res.length - 1){
            resList = new ListNode(res[i]);
            temp = resList;
        } else {
            temp.next = new ListNode(res[i]);
            temp = temp.next;
        }
    }
    return resList;
};
```