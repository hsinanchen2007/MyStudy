### 解题思路
通过递归的方式进入数据链，然后在计算
### (进)递归这就是正常的递归
``` javascript
var addTwoNumbers = function (p1, p2, x = 0) { // 因为有进1，所以需要在方法参数里面添加了一个 x
    let [obj, v1, v2, v3, v4] = [
        new ListNode(),
        p1 ? p1.val : 0, p2 ? p2.val : 0,
        p1 ? p1.next : null, p2 ? p2.next : null
    ]; // 递归需要判断 val 和 next 但为了好看所以写成了这样 
    let val_ = v1 + v2 + x;
    if (v3 != null || v4 != null) { // 判断是否继续进入递归
        const [l1, l2] = [val_ % 10, parseInt(val_ / 10)];
        /**
         * obj.val = l1;
         * obj.next = addTwoNumbers(v3, v4, l2); // 递归
         */
        [obj.val, obj.next] = [l1, addTwoNumbers(v3, v4, l2)];
    } else {
        obj.val = val_;
        // 无递归，但是为了防止最后出现 9 + 9 的情况 所以判断是否大于 9
        if (val_ > 9) [obj.val, obj.next] = [val_ % 10, new ListNode(1)];
    }
    return obj;
};
```
### (取)递归 ，主要是通过递归吧里面的值取出来
这是根据上面的递归演化而来的，但是好像这玩意除了内存开销比递归小好像没有一点用处还难看懂
```javascript
var addTwoNumbers = function (l1, l2, obj = new ListNode(0)) {
    let obj_ = obj;
    // 下面 for ;; 里面定义的递归的赋值 也就是下面的那句但是发现可能导致多一位0，ps：{1},{2}
    // for(; l1 || l2; [l1, l2] = [ l1 ? l1.next : null, l2 ? l2.next : null])
    for (let i = 0; l1 || l2; [i, l1, l2] = [i + 1, l1 ? l1.next : null, l2 ? l2.next : null]) {
        if (i != 0) { // {1}
            obj_.next = obj_.next == null ? new ListNode(0) : obj_.next;
            obj_ = obj_.next;
        }
        // 计算和取值，但是少了判断 next
        let [v1, v2] = [l1 ? l1.val : 0, l2 ? l2.val : 0];
        let val = obj_.val + v1 + v2;
        // 下面直接赋值
        [obj_.val, obj_.next] = [val > 9 ? val % 10 : val, val > 9 ? new ListNode(1) : null]; // {2}
    }
    return obj;
}
```