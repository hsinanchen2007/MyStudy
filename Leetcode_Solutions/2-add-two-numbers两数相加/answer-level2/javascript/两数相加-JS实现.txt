能力不足，不了解链表结构，这里的思路是先把入参的l1,l2 打印了下，发现是构造函数ListNode生成的实例。一开始看测试用例以为是数组相加。所以将入参先转数组，计算后再转回链表
```javascript []
var addTwoNumbers = function(l1, l2) {
    a1 = listNode2Array(l1)
    a2 = listNode2Array(l2)
    var aa = []
    if(a1.length < a2.length){
        aa = a1
        a1 = a2
        a2 = aa
    }
    var arr = []
    a1.forEach((i,j)=>{
        arr.push(i + (a2[j] || 0))
    })
    arr.forEach((i,j)=>{
        if(i>9){arr[j] = i%10; arr[j+1] ? arr[j+1] +=1 : arr[j+1] =1}
    })
    return array2ListNode(arr)
};
// 链表转数组
function listNode2Array(ListNode,val){
  var arr = val && val.length ? val : []
  arr.push(ListNode.val)
  if (ListNode.next){
    return listNode2Array(ListNode.next,arr)
  } 
  return arr
}
// 数组转链表
function array2ListNode(arr){
  var line = arr.map((i,j)=>{
    return new ListNode(i)   
  })
  for(var j = 0;j<= line.length; j++){
    line[j+1] && (line[j].next = line[j+1])
  }
  return line[0]
}

```