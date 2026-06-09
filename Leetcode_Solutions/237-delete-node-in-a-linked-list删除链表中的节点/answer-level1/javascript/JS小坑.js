> 首先说明，真的没看懂这道题的意思。脑补：为啥这个方法只要传一个参数？在哪删？到底让我删除啥？然后看了官方题解之后。。。这题目描述写的真差
## 第一版
```javascript []
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
var deleteNode = function(node) {
  node.val = node.next.val;
  node.next = node.next.next;
};
```
 分析：其实这题过于简单没啥好分析的

## 第二版（误），提交第一版之后发现貌似有更简单的方法，然后改成了下面这样
```javascript []
var deleteNode = function(node) {
  node = node.next;
};
```
 但是执行之后没有得到正确的结果。。。看到执行结果后，立即想到我可能踩到了多年不曾踩过的一个JS坑点。
### 下面直接写原因吧
## JS中基本类型按值引用，对象类型按地址引用

```javascript
let a = {};
let b = a;
a.val = 1; // 此时 a → { val: 1 }, b → { val, 1 }
a = {}; // 此时 a → {}, b → { val, 1 }
```
1. 在JS中，以上代码段中的**a其实只是保存了一个内存中的地址**，每次使用a的时候其实是通过地址去找到真正的`{}`
2. 而将a赋值给b，其实就是将a保存的地址复制给b一份，然后调用b也会去找到和a相同地址的`{}`
3. `a.val = 1`就是将a地址指向的对象`{}`增加一个值为1的属性val
4. 因为b保存的地址也指向同一个对象，所以看起来就像是b也在同步变化。其实b保存的地址并没有变化。
5. `a = {}`则将一个新的`{}`的地址赋值给了a，此时覆盖掉了原来保存的`{ val: 1 }`对象的地址，然而b所保存的地址仍然指向原来的`{ val: 1 }`
#### 放到本题来说就是题目给的参数node（相当于示例中的b）只是题意链表中的对应节点（相当于示例中的a）的地址副本，对node（b）赋值相当于直接覆盖掉这个副本的值，但是原节点（a）保存的地址并不会变。对node.next和node.val赋值才是真正的操作链表对应节点的内容。

---
---
---
> 唉，一道简单的题，本来不想写题解的。但是还是写了这么多，就当纪念自己终将逝去的菜吧。（没想到还会踩这么简单的坑）

