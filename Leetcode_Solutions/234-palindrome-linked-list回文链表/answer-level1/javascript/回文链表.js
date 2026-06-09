### 解题思路
方法一、存入数组，反转，一一比较

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
    while(head!=null){
        arr.push(head.val);
        head=head.next;
    } 
    //var arr_2=arr.reverse();注意不能将数组reverse之后赋值给另外一个变量，数组使用reverse函数之后，数组本身已经发生变化
    for(var i=0;i<=arr.length;i++){
        if(arr[i]!=arr.reverse()[i]){
            return false;
        }
    }
    return true;
};
```
方法二、
存入数组，判断队列和数组是否一一对应相等
```
var isPalindrome = function(head) {
    var arr=[];
    var p=head;
    if(head==null)return true;
    while(head!=null){
        arr.push(head.val);
        head=head.next;
    }
    var i=arr.length;
    while(p){
        if(p.val!=arr[i-1]){
            return false;
        }
        p=p.next;
        i--;
    }
    return true;
};
```
方法三、快慢指针，参考https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-1zhan-2kuai-man-zhi-zhen-fan-zhu/
