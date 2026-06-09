### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const result = [];
    const book = {};
    const res = [];
    // 深度优先遍历，排列组合，思路类似于有n个萝卜，填k个坑
    // 步骤示意图：
    // dfs(0) 1 -> dfs(1) -> 由于萝卜1已被用，所以1不能用，跳过，填2，-> dfs(2) -> 和前面相似，这里只能填3-> 最后一步，把当前结果填到集合；
    // 回溯到dfs(1), 这里还可以填3，然后再填2，最后得到1-> 3 -> 2 。把当前结果填到集合；
    // 第二个坑位回溯完，然后再回溯到第一个坑位
    // 第一个坑位可以先填2，
    // 然后依次得到： 2->1->3， 2->1->3
    // 。。。   
    function dfs(step, targetArr) {
        const total = targetArr.length;
        // 当轮询完所有坑位时，将前面轮询的结果放入最后的集合中
        if (step === total) {
            result.push(res.slice());
            return;
        }
        for (let i = 0; i < total; i++) {
            const target = targetArr[i];
          if (!book[target]) {
            res[step] = target;
            // 标记：当前坑位已经被占用
            book[target] = 1;
            dfs(step + 1, targetArr);
            // 当前轮次已排完，清除标记
            book[target] = 0;
          }
        }
    }
    dfs(0, nums);
    return result;
};
```