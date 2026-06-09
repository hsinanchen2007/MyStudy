> 每日更新 1+ 刷题，欢迎 star [Nodreame: Leetcode-note-js](https://github.com/Nodreame/leetcode-note-js)

- 刷题进度:
    - [x] 迭代法
    - [x] 自递归法 -- 反转后尾接
    - [x] 尾递归法
- 难度: easy.
- 题意解析: 反转给定链表.
- 输入处理: head为空直接返回空.
- 初始思路: 迭代法
    - 思路: 设置一个前指针prev和推进指针curr，推进直到curr为空，返回prev.
    - 复杂度分析:
        - 时间: O(n). 逐个推进故 O(n).
        - 空间: O(1). 只用到了常数级额外空间故 O(1).
    - Leetcode 结果:
        - 执行用时: 60 ms, 在所有 JavaScript 提交中击败了 99 %的用户
        - 内存消耗: 34.9 MB, 在所有 JavaScript 提交中击败 51 %的用户
    - 实现:
        ``` js
        var reverseList = function(head) {
            let [prev, curr] = [null, head];
            while (curr) {
                let tmp = curr.next;    // 1. 临时存储当前指针后续内容
                curr.next = prev;       // 2. 反转链表
                prev = curr;            // 3. 接收反转结果
                curr = tmp;             // 4. 接回临时存储的后续内容
            }
            return prev;
        };
        ```
    - 简化实现：
        ``` js
        var reverseList = function(head) {
            let [prev, curr] = [null, head];
            while (curr) {
                [curr.next, prev, curr] = [prev, curr, curr.next];
            }
            return prev;
        };
        ```
- 第二思路: 自递归法 -- 反转后尾接
    - 思路: 自递归无法存储推进状态所以无法尾递归，不断将 next 放入递归方法反转链表，结果.next = 当前节点. （Tip: 记得推进结果直到 next.next 为空）
    - 复杂度分析:
        - 时间: O(n). 从最底层两个节点反转开始，每层时间复杂度均为 O(1), 总共 n-1 层递归，故时间复杂度为 O(n).
        - 空间: O(n). 递归调用栈消耗空间，共 n-1 层递归，故空间复杂度为 O(n).
    - Leetcode 结果:
        - 执行用时: 68 ms, 在所有 JavaScript 提交中击败了 85 %的用户
        - 内存消耗: 35.2 MB, 在所有 JavaScript 提交中击败 24 %的用户
    - 实现(反转后尾接，省去推进过程):
        ``` js
        var reverseList = function(head) {
            if (!head || !head.next) return head;
            let next = head.next; // next节点，反转后是最后一个节点
            let reverseHead = reverseList(next);
            head.next = null; // 裁减 head
            next.next = head; // 尾接
            return reverseHead;
        };
        ```
- 第三思路: 尾递归法
    - 思路: 用 prev 和 curr 存储推进状态，直到 curr 为空则输出结果.
    - 复杂度分析:
        - 时间: O(n). 等同于正常推进，故 O(n).
        - 空间: O(1). 尾递归方式，重复使用一个空间故空间复杂度为 O(1).
    - Leetcode 结果:
        - 执行用时: 60 ms, 在所有 JavaScript 提交中击败了 98 %的用户
        - 内存消耗: 35.2 MB, 在所有 JavaScript 提交中击败 27 %的用户
    - 实现:
        ``` js
        var reverseList = function(head) {
            return reverse(null, head);
        };

        function reverse (prev, curr) {
            if (!curr) return prev;
            // [curr.next, prev, curr] = [prev, curr.next, curr.next];
            let tmp = curr.next;
            curr.next = prev;
            return reverse(curr, tmp);
        }
        ```