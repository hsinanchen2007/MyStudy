### 解题思路
此处撰写解题思路

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
 * @return {boolean}
 */
var isPalindrome = function(head) {
    var arr=[];
    var flag=true;
    while(head){
        arr.push(head.val)
        head = head.next
    }
    console.log(arr)
    for(let i=0;i<arr.length/2;i++){
        console.log(arr[i])
        console.log(arr[arr.length-i-1])
        if(arr[i]!=arr[arr.length-i-1]){
            flag = false;
        }
    }
    return flag
};
```

将ListNode转化成数组，然后遍历数组以中间为分界点判断对称位置的数字是否相等