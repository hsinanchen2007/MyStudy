> 每日更新 1+ 刷题，欢迎 star [Nodreame: Leetcode-note-js](https://github.com/Nodreame/leetcode-note-js)
- 刷题进度:
    - [x] 递归法(DFS).
    - [x] 迭代法(DFS).
    - [x] 迭代法(BFS).
    - [x] 递归法(BFS).
- 难度: easy.
- 题意解析: 给定二叉树，求所有左叶子节点之和;
- 输入处理: 空树返回0.
- 初始思路: 递归法(DFS).
    - 思路: 用数组缓存结果.
    - 复杂度分析:
        - 时间: O(n).
        - 空间: O(1).
    - Leetcode 结果:
        - 执行用时: 60 ms, 在所有 JavaScript 提交中击败了 97.3 %的用户
        - 内存消耗: 34.1 MB, 在所有 JavaScript 提交中击败 55.5 %的用户
    - 实现:
        ``` js
        var sumOfLeftLeaves = function(root) {
            let res = [0];
            recursion(root, false, res);
            return res[0];
        };

        function recursion(node, isLeft, res) {
            if (!node) return;
            if (!node.left && !node.right && isLeft) {
                res[0] += node.val;
            }
            if (node.left) recursion(node.left, true, res);
            if (node.right) recursion(node.right, false, res);
        }
        ```
- 第二思路: 迭代法(DFS). 
    - 思路: 用迭代实现DFS递归思路.
    - 复杂度分析:
        - 时间: O(n).
        - 空间: O(1).
    - Leetcode 结果:
        - 执行用时: 60 ms, 在所有 JavaScript 提交中击败了 97.3 %的用户
        - 内存消耗: 33.7 MB, 在所有 JavaScript 提交中击败 100 %的用户
    - 实现:
        ``` js
        var sumOfLeftLeaves = function(root) {
            if (!root) return 0;
            let stack = [root];
            let res = 0;
            while (stack.length > 0) {
                let tmp = stack.pop();
                if (!tmp.left && !tmp.right && tmp.isLeft) res += tmp.val;
                if (tmp.right) stack.push(tmp.right);            
                if (tmp.left) {
                    tmp.left.isLeft = true;
                    stack.push(tmp.left);            
                }
            }
            return res;
        };
        ```
- 第三思路: 迭代法(BFS).
    - 思路: 层次遍历.
    - 复杂度分析:
        - 时间: O(n).
        - 空间: O(logn). 队列最多存储最底层元素.
    - Leetcode 结果:
        - 执行用时: 56 ms, 在所有 JavaScript 提交中击败了 98.6 %的用户
        - 内存消耗: 34.1 MB, 在所有 JavaScript 提交中击败 55.6 %的用户
    - 实现:
        ``` js
        var sumOfLeftLeaves = function(root) {
            if (!root) return 0;
            let res = 0;
            let queue = [root];
            while (queue.length > 0) {
                for (let i=0, len=queue.length; i<len; i++) {
                    let tmp = queue.shift();
                    if (!tmp.left && !tmp.right && tmp.isLeft) res += tmp.val;
                    if (tmp.left) {
                        tmp.left.isLeft = true;
                        queue.push(tmp.left);
                    }
                    if (tmp.right) queue.push(tmp.right);
                }
            }
            return res;
        };
        ```
- 第四思路: 递归法(BFS).
    - 思路: 层次遍历.
    - 复杂度分析:
        - 时间: O(n).
        - 空间: O(logn). 队列存储.
    - Leetcode 结果:
        - 执行用时: 60 ms, 在所有 JavaScript 提交中击败了 97.3 %的用户
        - 内存消耗: 34.8 MB, 在所有 JavaScript 提交中击败 22.2 %的用户
    - 实现:
        ``` js
        var sumOfLeftLeaves = function(root) {
            if (!root) return 0;
            return recursion([root]);
        };

        function recursion (nodeArr) {
            if (nodeArr.length === 0) return 0;
            let res = 0;
            let arr = [];
            for (let i=0, len = nodeArr.length; i<len; i++) {
                let tmp = nodeArr[i];
                if (!tmp.left && !tmp.right && tmp.isLeft) res+=tmp.val;
                if (tmp.left) {
                    tmp.left.isLeft = true;
                    arr.push(tmp.left);
                }
                if (tmp.right) arr.push(tmp.right);
            }
            return recursion(arr) + res;
        }
        ```