解一（伪）：
> 因为前一天晚上做了八皇后，用的是回溯。所以想着这道题应该也可以用回溯做。结果呢，时间复杂度是$O(n^n)$，超出时间限制了。

```js
var lengthOfLIS = function(nums) {
    if (nums.length===0) return 0
    var ans = 1;
    var temp_ans = [];

    var add = function(index) { //类比八皇后的placeQueen()
        temp_ans.unshift(nums[index])
    }

    var undo = function() { //类比八皇后的removeQueen()
        temp_ans.shift()
    }

    var backtrack = function(i) {
        for (let j=i+1;j<nums.length;j++){ //探索i之后每一个元素
            if (nums[j]>temp_ans[0]) {
                add(j);
                ans = Math.max(ans,temp_ans.length);
                if (j<nums.length-1) backtrack(j);
                undo()
            }
        }
    }

    for (var i=0; i<nums.length; i++){ //假设子序列从第i个元素开始
        temp_ans = [nums[i]];
        backtrack(i);
    }
    return ans;
};
```

解二：
> 有记忆的递归（因为暂时不知道怎么做有记忆的回溯🤣）

```js
var lengthOfLIS = function(nums) {

    var memory = []; //memory[i][j]记忆为二维数组，对应recurse[i-1][j]的输出
    memory = Array(nums.length+1).fill(-1).map(()=>Array(nums.length).fill(-1)) //初始化为-1

    var recurse = function(prev, cur){ 
        //prev表示上一个加入子序列的元素坐标（也即子序列当前最大元素的坐标）
        //cur表示当前到达的元素坐标
        if (cur === nums.length) return 0;
        if (memory[prev+1][cur]>=0) return memory[prev+1][cur];

        var taken = 0; //1.考虑cur在内
        if (prev<0||nums[cur]>nums[prev]) taken = 1+recurse(cur,cur+1); 
        var nottaken = recurse(prev,cur+1); //2.不考虑cur在内
        memory[prev+1][cur] = Math.max(taken,nottaken)

        return memory[prev+1][cur];
    }

    return recurse(-1,0)
};
```

解三：
> 动态规划。不同于解二维护的是一个二维数组`memory`，这里维护一个一维数组`bp`。`bp[i]`表示以第i个元素**结尾**的最长子序列长度。

```js
var lengthOfLIS = function(nums) {
    var dp = new Array(nums.length).fill(1);
    var ans = 0;
    for (var i=0; i<nums.length;i++){ //对于第i个元素nums[i]
        for (var j=0; j<i;j++){ //遍历i前面的i-1个元素
            if (nums[j]<nums[i]) dp[i] = Math.max(dp[i],dp[j]+1)
            //如果nums[j]比nums[i]小 更新dp[i]
        }
        ans = Math.max(ans,dp[i]);
    }
    return ans
};
```

解四：
> 动态规划+二分查找。注意这里的`ans`并不一定是题目中要求的最长递增子序列，只是长度与其相等。

```js
var lengthOfLIS = function(nums) {
    var ans = []; //记录子序列
    for (var i = 0; i < nums.length; i++) {
        var left = 0, right = ans.length;
        while (left < right) { //二分法
            var mid = left + right >>> 1;
            if (ans[mid] < nums[i]) left = mid + 1;
            else right = mid;
        } //在ans数组中找到第一个大于等于nums[i]的元素
        if (right >= ans.length) ans.push(nums[i]); //找不到 在ans最后增加一项nums[i]
        else ans[right] = nums[i];//找到 替换
    }
    return ans.length;
};
```

对于一个乱序序列`4 2 4 5 3 7`的执行过程如下：
```
->i=0 l=0 r=0
没进去while ans[0]=nums[0]=4

->i=1 l=0 r=1 nums[i]=2
找到并替换ans[0]=2 ans=[2]

->i=2 l=0 r=1 nums[i]=4
找不到 ans=[2,4]

->i=3 l=0 r=2 nums[i]=5
找不到 ans=[2,4,5]

->i=4 l=0 r=3 nums[i]=3
找到并替换ans[1]=3 ans=[2,3,5]

->i=5 l=0 r=4 nums[i]=7
找不到 ans=[2,3,5,7]
```