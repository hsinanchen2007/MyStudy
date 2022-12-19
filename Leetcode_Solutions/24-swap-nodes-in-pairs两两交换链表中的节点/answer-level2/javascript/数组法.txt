### 解题思路
![微信截图_20200224221351.png](https://pic.leetcode-cn.com/720a6c7a35266ded841e204206948d1c8d731f0b38215a16e0e50db6a699f4a7-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200224221351.png)
数组法：时间复杂度：O(n)
1.首先遍历链表，取出所有节点的值并push进数组中
2.以数组中的值创建新的链表。遍历数组，以i+=2来进行遍历，每一次先创建值arr[i+1]的节点，再创建arr[i]的节点。注意arr[i+1]可能出现不存在的情况，需要以判断
3.考虑边界情况：链表为空，则返回null；链表长度为1，则直接返回。
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
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if(!head)return null
    if(!head.next)return head
    let arr=[]
    while(head!==null){
        arr.push(head.val)
        head=head.next
    }
    let len=arr.length
    let result=new ListNode(-1)
    let tmp=result
    for(let i=0;i<len;i+=2){
        if(arr[i+1]!==undefined){
            tmp.next=new ListNode(arr[i+1])
            tmp=tmp.next
        }
        tmp.next=new ListNode(arr[i])
        tmp=tmp.next
    }
    return result.next
};
```