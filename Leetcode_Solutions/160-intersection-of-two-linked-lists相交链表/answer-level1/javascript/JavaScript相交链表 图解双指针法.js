解一：
> 先遍历`headA`并打上标记，再遍历`headB`寻找标记。

```js
var getIntersectionNode = function(headA, headB) {
    while(headA){
        headA.sep = 1;
        headA = headA.next;
    }
    while(headB){
        if(headB.sep) return headB
        headB = headB.next;
    }
};
```

解二：
> 嵌套循环。

```js
var getIntersectionNode = function(headA, headB) {
    while(headA){
        var temp = headB;
        while(temp){
            if(temp===headA) return headA;
            temp=temp.next
        }
        headA=headA.next;
    }
};
```

解三：
> 双指针法。初始化两个指针`pA`和`pB`分别指向`headA`和`headB`，每次`pA`和`pB`各走一步，当`pA`触底后变轨到`headB`，同理，当`pB`触底后变轨到`headA`。这样就只需遍历（`A`的非公共部分+`B`的非公共部分+`AB`的公共部分）。
> 
> 我画了一张图，方便理解：
> ![](https://pic.leetcode-cn.com/914957a14491d611f4441c9bfbcaa14a81126523c55152a23db27707b5ef8118-file_1567819667728)


```js
var getIntersectionNode = function(headA, headB) {
    var pA = headA;
    var pB = headB;
    while(pA !== pB){
        pB = pB? pB.next: headA;
        pA = pA? pA.next: headB;
    }
    return pA;
};
```

![](https://pic.leetcode-cn.com/efcacd8383e77d9601e75e9516452a0b8463630e4161eccb0336b7fb83ae1b99-file_1567819667695)