js 回溯法 | 暴力DFS
```js
// 回溯法
        /**
         * Definition for a binary tree node.
         * function TreeNode(val) {
         *     this.val = val;
         *     this.left = this.right = null;
         * }
         */
        /**
         * @param {TreeNode} root
         * @param {number} sum
         * @return {number[][]}
         */
        var pathSum = function(root, sum) {
            if (!root) return [];
            const res = [];
            const children = ['left', 'right'];
            function dfs(parent, path) {
                path.push(parent.val);
                if (!parent.left && !parent.right) {
                    if(parent.sum === sum) res.push(path.slice(0));
                    path.pop(parent.val);
                    return;
                }
                children.forEach(child => {
                    if(parent[child]) {
                        parent[child].sum = parent.sum + parent[child].val;
                        dfs(parent[child], path);
                    }
                })
                path.pop(parent.val);
            }
            root.sum = root.val;
            dfs(root, [])
            return res;
        }
        
        // 暴力法
        /**
         * Definition for a binary tree node.
         * function TreeNode(val) {
         *     this.val = val;
         *     this.left = this.right = null;
         * }
         */
        /**
         * @param {TreeNode} root
         * @param {number} sum
         * @return {number[][]}
         */
        var pathSum = function(root, sum) {
            if(!root) return [];
            const pre = {};
            const idMap = {};
            let id = 1;
            root.sum = root.val;
            root.id = id++;
            idMap[root.id] = root.val;
            const stack = [root];
            let i = stack.length;
            const target = [];
            const children = ['left', 'right'];
            while(i) {
                while(i--) {
                    const front = stack.pop();
                    if (!front.left && !front.right && front.sum === sum) target.push(front.id);
                    children.forEach(child => {
                        if(front[child]) {
                            front[child].id = id++;
                            front[child].sum = front.sum + front[child].val;
                            idMap[front[child].id] = front[child].val;
                            stack.push(front[child]);
                            pre[front[child].id] = front.id;
                        }
                    })
                }
                i = stack.length;
            }
            return target.map(tail => {
                const res = [];
                let front = tail;
                while(front) {
                    res.unshift(idMap[front]);
                    front = pre[front];
                }
                return res;
            })
        };
```
