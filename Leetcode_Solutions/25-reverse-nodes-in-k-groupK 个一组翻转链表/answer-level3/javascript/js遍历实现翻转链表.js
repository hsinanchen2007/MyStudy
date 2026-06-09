- js 尽量使用let
- 代码略复杂,具体看注释
    - 通过将要翻转的链表进行分组,左边分过的,中间要分的,右边未分的
    - 其中要注意反转第一组时,要用一个对象记录结果的第一个node
    - 最后一组要判断是否满足k个,要够k个再反转
    - 反转时要主要保留前后两个节点,记得将要反转的节点组前后先都为空


```js
	// 反转链表
	let reverseList = function(headTemp) {
		let head = headTemp;
		let pre = null;
		let post = null;
		while (head !== null) {
			post = head.next;
			head.next = pre;
			pre = head;
			head = post;
		}
		return pre;
	};

	let getEndNode = function(head, k) {
		for (let i = 0; i < k - 1; i++) {
			if (head == null) {
				return false;
			}
			// 这里的head,可能返回null,当i=k-1,但是head.next == null
			head = head.next;
		}
		return head;
	}

	// K 个元素为一组交换
    // 需要3个节点记录,并且以head为轴,进行处理
	let reverseKGroup = function(head, k) {
		let first = null;
		let pre = null;
		while (head != null) {
			let start = head;
			let end = getEndNode(head, k);
			// end 为false 或则 null,说明剩下的不足k
			if (end === false || end === null) {
				return first;
			} else {
				head = end.next;
			}
			end.next = null;
			reverseList(start)
			start.next = head;
            // 第一次反转时,pre是null
			if (pre != null) {
				pre.next = end;
			} else {
                // 取得第一组的反转后的第一个
				first = end;
			}
            // pre指向start,作为下一次分组的开始
			pre = start;
		}
		return first;
	}

```