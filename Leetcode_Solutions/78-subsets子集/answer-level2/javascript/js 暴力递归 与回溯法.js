js 暴力递归
```js
        /** 
         * @param {number[]} nums
         * @return {number[][]}
         */
        var subsets = function(nums) {
            const res = [];
            function backtrack(path, i) {
                res.push(path);
                // 回溯过程
                for(let j = i; j < nums.length; j++) {
                    path.push(nums[j]);
                    backtrack(path.slice(), j + 1);
                    path.pop();
                }
            }
            backtrack([], 0);
            return res;
        };

        // 暴力dfs
        var subsets = function(nums) {
            const res = [[]];
            function dfs(i, path) {
                if(i === nums.length) path && res.push(path.split(',').map(i => +i));
                else {
                    dfs(i + 1, path);
                    dfs(i + 1, path ? path + ',' + nums[i] : '' + nums[i]);
                }
            }
            dfs(0, '');
            return res;
        };
};
```
