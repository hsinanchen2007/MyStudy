> 每日更新 1+ 刷题，欢迎 star [Nodreame: Leetcode-note-js](https://github.com/Nodreame/leetcode-note-js)
- 刷题进度:
    - [x] 归并递归法(空间复杂度不符合题意)
    - [x] 归并迭代法(不截断)
    - [x] 归并迭代法(截断)
- 难度: medium
- 题意解析: 对给定链表进行排序，要求时间复杂度为O(nlogn), 空间复杂度为O(1).
- 输入处理: 给定链表为空 & 链表长度为1时，直接返回.
- 初始思路: 归并递归法.
    - 思路: 不断二分再归并.
    - 复杂度分析:
        - 时间: O(nlogn).
        - 空间: O(logn).
    - Leetcode 结果:
        - 执行用时: 116 ms, 在所有 JavaScript 提交中击败了 81 %的用户
        - 内存消耗: 41.8 MB, 在所有 JavaScript 提交中击败 32 %的用户
    - 实现:
        ``` js
        var sortList = function(head) {
            // 递归思想：
            if (!head || !head.next) return head;
            //  1. 快慢针二分，前一半截断并获取后一半开始节点(奇数中间，偶数中前)
            let [slow, fast, mid] = [head, head.next, null];
            while (fast && fast.next) [slow, fast] = [slow.next, fast.next.next];
            [slow.next, mid] = [null, slow.next]
            // 2. 左右递归；
            let [left, right] = [sortList(head), sortList(mid)];
            // 3. 合并递归结果左右链表 @#21
            let curr = res = new ListNode(null);
            while (left && right) {
                if (left.val < right.val) [curr.next, left] = [left, left.next];
                else [curr.next, right] = [right, right.next];
                curr = curr.next;
            }
            curr.next = left ? left : right;
            //  4. return 空节点.next;
            return res.next;
        };
        ```
- 第二思路: 归并迭代法(不截断).
    - 思路: 两两比较合并.
    - 复杂度分析:
        - 时间: O(nlogn). 每次长度*2推进复杂度 O(logn)，中间逐个推进 O(n).
        - 空间: O(1). 原地归并故O(1).
    - Leetcode 结果:
        - 执行用时: 264 ms, 在所有 JavaScript 提交中击败了 23.8 %的用户
        - 内存消耗: 49.2 MB, 在所有 JavaScript 提交中击败 8.8 %的用户
    - 实现:
        ``` js
        var sortList = function(head) {
            // 不截断归并：
            //  0. head 为空或只有一个，直接返回
            if (!head || !head.next) return head; 
            //  1. 获取链表长度
            let [tmp, count] = [head, 0];
            while (tmp) [tmp, count] = [tmp.next, count+1];
            //  2. 创建结果空节点 res
            let res = new ListNode(null);
            res.next = head;
            //  3. 获取左右链表循环开始，先是步长为1（单节点），步长不断*2，直到超过链表长度
            //      3.0 用 prev 做替身，curr 做临时工, 每次更新步长则重来
            //      3.1 获取左链表，按步长推进，获取右链表，按步长推进；
            //      3.2 对比排序循环开始，由于不截断，故循环对比排序条件只能用当前左右链表长度；
            //      3.3 用 prev 接收为左右中的未完链表；
            //      3.4 用剩余长度推进 prev;
            //      3.5 用 prev.next 接收 curr;
            for (let i=1; i<count; i*=2) {
                let [prev, curr] = [res, res.next];
                while (curr && curr.next) {
                    let [n1, n2, step] = [curr, null, i];
                    while (curr && step) [curr, step] = [curr.next, step-1];
                    if (step) break; // 无后续节点，长度不足
                    [n2, step] = [curr, i];
                    while (curr && step) [curr, step] = [curr.next, step-1];
                    let [l1, l2] = [i, i-step];
                    while (l1 && l2) {
                        if (n1.val < n2.val) [prev.next, n1, l1] = [n1, n1.next, l1-1];
                        else [prev.next, n2, l2] = [n2, n2.next, l2-1];
                        prev = prev.next;
                    }
                    prev.next = l1 ? n1 : n2;
                    while (l1>0 || l2>0) [prev, l1, l2] = [prev.next, l1-1, l2-1];
                    prev.next = curr;
                }
            }
            //  4. 返回
            return res.next;
        };
        ```
- 第三思路: 归并迭代法(截断).
    - 思路: 类似第二思路，但是每次都会截断和合并.
        - 参考：[ivan_allen的答案](https://leetcode-cn.com/problems/sort-list/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/)
    - 复杂度分析:
        - 时间: O(nlogn). 同上.
        - 空间: O(1). 原地归并.
    - Leetcode 结果:
        - 执行用时: 140 ms, 在所有 JavaScript 提交中击败了 38.9 %的用户
        - 内存消耗: 45 MB, 在所有 JavaScript 提交中击败 17.6 %的用户
    - 实现:
        ``` js
        var sortList = function(head) {
            if (!head || !head.next) return head;
            let [tmp, count] = [head, 0];
            while (tmp) [tmp, count] = [tmp.next, count+1];
            
            let res = new ListNode(null);
            res.next = head;
            for (let i=1; i<count; i*=2) {
                let [prev, curr] = [res, res.next];
                while (curr) {
                    let n1 = curr;
                    let n2 = cut(n1, i);
                    curr = cut(n2, i);
                    
                    prev.next = merge(n1, n2);
                    while (prev.next) prev = prev.next;
                }
            }
            return res.next;
        };

        function cut (head, size) {
            let curr = head;
            while (--size && curr) curr = curr.next;
            if (!curr) return null;
            let next = curr.next;
            curr.next = null;
            return next;
        }

        function merge (n1, n2) {
            let res = new ListNode(null);
            let prev = res;
            while (n1 && n2) {
                if (n1.val < n2.val) [prev.next, n1] = [n1, n1.next];
                else [prev.next, n2] = [n2, n2.next];
                prev = prev.next;
            }
            prev.next = n1 ? n1 : n2;
            return res.next;
        }
        ```
