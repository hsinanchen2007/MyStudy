> 每日更新 1+ 刷题，欢迎 star [Nodreame: Leetcode-note-js](https://github.com/Nodreame/leetcode-note-js)
- 刷题进度:
    - [x] 迭代法.
    - [x] 自递归法.
- 难度: medium.
- 题意解析: 将给定的链表的两两节点进行交换，要求发生实际节点交换.
- 输入处理: 输入链表为空及长度为1时，直接返回输入值.
- 初始思路: 迭代法.
    - 思路: 使用哨兵头节点， 推进指针prev从当前哨兵节点位置出发，故prev.next=head，确认接下来两个节点(prev.next, prev.next.next)是否为空
        - 若不为空则开始交换: a为prev.next, b为prev.next.next, 同时发生prev.next=b, a.next=b.next, b.next=a; prev推进两格; 循环继续;
        - 若有一个或一个以上为空则直接返回哨兵head节点的next;
    - 复杂度分析:
        - 时间: O(n). 推进遍历整个链表故O(n).
        - 空间: O(1). 使用常量级空间.
    - Leetcode 结果:
        - 执行用时: 60 ms, 在所有 JavaScript 提交中击败了 94 %的用户
        - 内存消耗: 33.9 MB, 在所有 JavaScript 提交中击败 12.3 %的用户
    - 实现:
        ``` js
        var swapPairs = function(head) {
            // 1. 确认 head 大于等于两个，否则返回;
            if (!head || !head.next) return head;
            // 2. 新建链表哨兵头并创建指针curr；
            let res = new ListNode(null);
            res.next = head;
            let prev = res;
            // 3. 循环开始
            //    3.1 走两步，存为fst, snd;
            //    3.2 哨兵->snd, fst->snd.next, snd->fst;
            //    3.3 推进 curr = curr.next.next;
            while (prev.next && prev.next.next) {
                let [fst, snd] = [prev.next, prev.next.next];
                [prev.next, fst.next, snd.next] = [snd, snd.next, fst];
                prev = prev.next.next;
            }
            // 4. 返回res.next;
            return res.next;
        };
        ```
- 第二思路: 自递归法.
    - 思路: 明确输入、终止条件、返回值、递归方法逻辑
        - 输入：自递归的输入恒为第一个节点;
        - 终止条件：输入为空或者输入.next为空;
        - 返回值：已经完成交换的后续链表;
        - 递归方法逻辑：同上面方法，res = 1.next && 1.next=已完成交换的后续链表 && res.next = 1
    - 复杂度分析:
        - 时间: O(n). 从最底层两个互换到最高层，每层时间复杂度均为O(1), 共 n/2 层故时间复杂度为 O(n/2).
        - 空间: O(n). 共 n/2 层递归调用栈， 故空间复杂度为 O(n/2).
    - Leetcode 结果:
        - 执行用时: 60 ms, 在所有 JavaScript 提交中击败了 94.8 %的用户
        - 内存消耗: 33.6 MB, 在所有 JavaScript 提交中击败 63.6 %的用户
    - 实现:
        ``` js
        var swapPairs = function(head) {
            // 自递归思路：
            //    1. 确认head大于等于两个，否则返回
            if (!head || !head.next) return head; 
            //    2. 获得第二个节点;
            let next = head.next;
            //    3. 第一个节点指向第三个节点, 传入第三个节点开始递归，获得已排序的链表；
            head.next = swapPairs(next.next);
            //    4. 第二个节点指向第一个节点
            next.next = head;
            //    5. 返回第二个节点；
            return next;
        };
        ```
    - 实现二:
        ``` js
        var swapPairs = function(head) {
            if (!head || !head.next) return head;
            let [fst, snd] = [head, head.next];
            [fst.next, snd.next] = [swapPairs(snd.next), fst];
            return snd;
        };
        ```