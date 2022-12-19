# 暴力【两遍遍历】
第一遍 转换为数组
第二遍 转换为交换列表

会被鄙视

# 迭代
边遍历,边处理,依赖四个值,三个指针,记录第一个值,结果直接出来
```javascript
var swapPairs = function(head) {
    //至少有两个值
    if(!head || !head.next){
        return head;
    }
    //缓存返回结果 【要求返回2】
    let r = head.next;
    //记录上一个记录 【指1前面可能存在的0】
    let _p1 = null;
    while(head && head.next ){
        //1
        let pre = head;
        //2
        let curryNode = head.next;
        //3
        let next = head.next.next;
        //2的next改为1
        curryNode.next = pre;
        //1的next改为3
        pre.next = next;
        //假设1前面有0 ,则将0指向2
        _t&&(_t.next=curryNode);
        //2,为下一个循环的上个节点
        _t = pre;
        //3,为下一个节点的pre
        head = next;
    }
    return r;
};
```
## 空对象优化
将null转换为无意义的空对象【类似于noop】,以减少if判断
```javascript
var swapPairs = function(head) {
    //记录四个值 改变 三个指针
    //至少有两个值
    if(!head || !head.next){
        return head;
    }
    let r = head.next;
    //记录上一个记录
    let p0 = new ListNode();
    p0.next = head;
    while(head && head.next ){
        //1
        let p1 = head;
        //2
        let p2 = head.next;
        //3
        let p3 = head.next.next;

        //2的next改为1
        p2.next = p1;
        //1的next改为3
        p1.next = p3;
        //假设1前面有0 ,则将0指向2
        p0.next=p2
        //2,为下一个循环的上个节点
        p0 = p1;
        //3,为下一个节点的pre
        head = p3;
    }
    return r;
};
```
## 冗余处理【依赖执行顺序】
包含空处理有,首次if判断可以取消(不在执行head)
减少中间值,有部分中间值并有没有改,可以直接使用
```javascript
var swapPairs = function(head) {
    //记录上一个记录
    let p0 = new ListNode();
    p0.next = head;
    let _temp  = p0;
    while(p0.next && p0.next.next ){
        //1
        let p1 = p0.next;
        //2
        let p2 = p1.next;
        
        //0指向2【不依赖变量p3,但依赖顺序】
        p0.next=p2
        //1的next改为3 
        p1.next = p2.next;
        //2的next改为1
        p2.next = p1;
        
        //2,为下一个循环的上个节点
        p0 = p1;
    }
    return _temp.next;
};
```

# 递归
递归四部套路,然后分析

```javascript
var swapPairs = function(head) {
    //1.停止条件
    if(head == null || head.next == null){
        return head;
    }
    //2.递归
    let p3 = swapPairs(head.next.next)
    //3.进行1 2 替换
    let p2 = head.next;
    //p1 指向 p3, head --> p1
    head.next = p3; //【可与递归合并】
    p2.next = head;
    //最后返回2 
    return p2;
};
```