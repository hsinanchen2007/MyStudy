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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    //  var al=strToList(l1);
    // var bl=strToList(l2);
/*
参考leecode的高手的，一开始使用简单的思维，先将链表转换为数字，然后用数字相加，
再把相加得到的结果转换为链表。
好像思路上是没什么问题
但是实际的测试用例有些数值比较大，js自动转为了科学计数法存储，
使用+得到的结果不太对。z
这个由于每一个位数的/ %操作都不会太大，计算不会错误
*/
let n = new ListNode(0);
    let root = n;
    let carry = 0;
	while(l1||l2||carry){
		let x1 = 0, x2 = 0;
		if(l1){
			x1=l1.val;
			l1=l1.next;
		}
		if(l2){
			x2=l2.val;
			l2=l2.next;
		}
		 let all = x1 + x2 + carry;
        carry = parseInt(all/10);
        n.next = new ListNode(all%10);
        n = n.next;
	}

return root.next;
};

function arrToList(arr){
	arr=arr.reverse();
	var len=arr.length;
	var rnum=parseInt(arr[len-1]);
	var root=new ListNode(rnum);
	var preNode=root;
	for(var i=len-2;i>=0;i--){
		var listnode=new ListNode(parseInt(arr[i]));
		preNode.next=listnode;
		preNode=listnode;
	}
	return root;
}
function strToList(str){
	// var root=new ListNode();
	var arr=str.split('->').reverse();
	var len=arr.length;
	var rnum=parseInt(arr[len-1]);
	var root=new ListNode(rnum);
	var preNode=root;
	for(var i=len-2;i>=0;i--){
		var listnode=new ListNode(parseInt(arr[i]));
		preNode.next=listnode;
		preNode=listnode;
	}
	return root;
}
function ListNode(val){
	this.val=val;
	this.next=null;
}
function listToNum(listnode){
	var num=0;
	var curNode=listnode;
	var index=0;
    	// var len=0;

	// while(curNode){
		// num+=curNode.val*Math.pow(10,index);
		// curNode=curNode.next;
		// index++;
	// 	len++;
	// }
	// curNode=listnode;

	while(curNode){
		if(curNode.val==0){
			// if(index==0){
			// 	num=0;
			// 	return num;
			// } else{
			// 	num+=Math.pow(10,index);
			// }
		}
		else{
			num+=curNode.val*Math.pow(10,index);
		}
		curNode=curNode.next;
		index++;
	}
	return num;
}
```