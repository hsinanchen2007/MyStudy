JavaScript刷题记录 [Leetcode-note-js](https://github.com/Nodreame/leetcode-note-js) , 欢迎 star.
- 刷题进度:
    - [x] 模板递归法(DFS)
    - [x] 模板状态迭代法(DFS)
    - [x] 模板状态迭代法(BFS)
    - [x] 模板递归法(BFS)
- 难度: medium
- 题意解析: 自顶向下逐层遍历并放入数组
- 初始思路: 模板递归法(DFS). 
    - 思路: 每层加上level做标记。某level第一次出现创建数组并插入res, 同level数值放入同一数组。
    - 复杂度:
        - 时间: O(n).等同二叉树节点个数，故为 O(n)
        - 空间: O(n).
    - Leetcode 结果:
        - 执行用时 : 72 ms, 在所有 JavaScript 提交中击败了 91 %的用户
        - 内存消耗 : 34.5 MB, 在所有 JavaScript 提交中击败 80 %的用户
    - 实现:
        ``` js
        var levelOrder = function(root) {
            if (!root) return [];    // 上提到这里，递归方法中无需再做处理
            let res = [];
            recursion(0, root, res);
            return res;
        }

        function recursion (level, node, res) {
            // 1. terminate

            // 2. process
            if (!res[level]) res[level] = [];
            res[level].push(node.val);
            // 3. drill down
            if (node.left) recursion(level+1, node.left, res);
            if (node.right) recursion(level+1, node.right, res);
            // 4. recover
        }
        ```
- 第二思路: 模板状态迭代法(DFS).
    - 思路: 给节点加上level开始迭代.
    - 复杂度分析:
        - 时间: O(n). 
        - 空间: O(n). 
    - Leetcode 结果:
        - 执行用时: 68 ms, 在所有 JavaScript 提交中击败了 96 %的用户
        - 内存消耗: 35.2 MB, 在所有 JavaScript 提交中击败 5.47 %的用户
    - 实现:
        ``` js
        var levelOrder = function(root) {
            if (!root) return [];
            let res = [];
            root.level = 0;
            let stack = [root];
            while (stack.length > 0) {
                let node = stack.pop();
                let level = node.level;
                if (!res[level]) res[level] = [];
                res[level].push(node.val);
                if (node.right) {
                    node.right.level = level + 1;
                    stack.push(node.right);
                }
                if (node.left) {
                    node.left.level = level + 1;
                    stack.push(node.left);
                }
            }
            return res;
        }
        ```
- 第三思路: 模板状态迭代法(BFS).
    - 思路: 创建res、queue、level. 提前将root塞进queue，以queue>0为条件开始循环. 先向res加入[]，然后再以queue长度为次数循环加 res 和 queue.
    - 复杂度分析:
        - 时间: O(n).满二叉树下while循环logn次，for循环次数分别为1, 2, 4..., 综合时间复杂度为O(n)
        - 空间: O(n).满二叉树情况下为约为O(n/2)，即最底层长度.
    - Leetcode 结果:
        - 执行用时 : 64 ms, 在所有 JavaScript 提交中击败了 98.34 %的用户
        - 内存消耗 : 35.1MB, 在所有 JavaScript 提交中击败 7.46 %的用户
    - 实现:
        ``` js
        var levelOrder = function(root) {
            if (!root) return [];
            let res = [];
            let queue = [];
            let level = 0;
            queue.push(root);
            
            // 1. terminate
            while (queue.length > 0) {
                res[level] = [];
                // 2.process
                for (let i=0, len=queue.length; i<len; i++) {
                    let node = queue.shift();
                    res[level].push(node.val);
                    // 3. drill down
                    if (node.left) queue.push(node.left);
                    if (node.right) queue.push(node.right);
                }
                level++;
            }
            return res;
        }
        ```
- 第四思路: 模板递归法(BFS).
    - 思路: 模仿BFS迭代思路，如果只是单节点递归最终必将沦为 DFS，故将一层的数据组合传递.
    - 复杂度分析:
        - 时间: O(n).
        - 空间: O(n).
    - Leetcode 结果:
        - 执行用时: 68 ms, 在所有 JavaScript 提交中击败了 96 %的用户
        - 内存消耗: 34.7 MB, 在所有 JavaScript 提交中击败 47 %的用户
    - 实现:
        ``` js
        var levelOrder = function(root) {
            if (!root) return [];
            let res = [];
            let queue = [root];
            recursion(queue, 0, res);
            return res;
        };

        function recursion (queue, level, res) {
            if (queue.length === 0) return;
            for (let i=0, len=queue.length; i<len; i++) {
                let temp = queue.shift();
                if (!res[level]) res[level] = [];
                res[level].push(temp.val);
                if (temp.left) queue.push(temp.left);
                if (temp.right) queue.push(temp.right);
            }
            recursion(queue, level+1, res);
        }
        ```