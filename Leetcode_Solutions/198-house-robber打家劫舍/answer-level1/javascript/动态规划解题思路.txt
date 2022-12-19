该问题是非常典型的、入门的动态规划问题。很多算法书上的都采用类似的例子来开始介绍动态规划。
### 设计动态规划的三个步骤
1. 将问题分解成最优子问题；
2. 用递归的方式将问题表述成最优子问题的解；
3. 自底向上的将递归转化成迭代；（递归是自顶向下）;

### 最优子问题
对于连续的 $n$ 栋房子：$H~1~,H~2~,H~3~......H~n~$，小偷挑选要偷的房子，且不能偷相邻的两栋房子，方案无非两种：    
**方案一**：挑选的房子中包含最后一栋；    
**方案二**：挑选的房子中不包含最后一栋；    
获得的最大收益的最终方案，一定在这两种方案中产生，用代码表述就是：   
`最优结果 = Math.max(方案一最优结果，方案二最优结果)`     

### 子问题的递归表述
```JavaScript []
var robTo = function (nums, lastIndex) {
    if (lastIndex === 0) {
        return nums[0];
    }

    // 方案一，包含最后一栋房子，则应该丢弃倒数第二栋房子
    let sum1 = robTo(nums, lastIndex - 2) + nums[lastIndex]; 

    // 方案二，不包含最后一栋房子，那么方案二的结果就是到偷到 lastIndex-1 为止的最优结果
    let sum2 = robTo(nums, lastIndex - 1); 

    return Math.max(sum1, sum2);
};
```
将问题表述成最优子问题的解后，这个问题就解决了：
```JavaScript []
var rob = function(nums) {
    return robTo(nums, nums.length - 1);
};
```
### 递归转迭代
到上一步为止，该问题就已经解决了。但是递归的方式性能太差，中间有太多重复的计算，所以还需要最后一步：将 *自顶向下* 的递归，转化成 *自底向上* 的迭代。
```JavaScript []
var rob = function(nums) {
    if (nums.length === 0) {
        return 0;
    }
    if (nums.length === 1) {
        return nums[0];
    }

    // 仍然用两个变量来存储方案一和方案二的最优结果
    // 不同的是，这次从0开始，lastIndex 取最小值 1
    let sum1 = nums[0];
    let sum2 = nums[1];

    // 然后通过迭代不断增大 lastIndex，过程中维护新的sum1，sum2，直到数组末尾
    for (let lastIndex=2; lastIndex<nums.length; lastIndex++) {
        let tmp = sum1;

        // 此时的方案一就是上一步中的方案二，
        // 但要求的是最优解，所以要判断前一步的 sum1 和 sum2 哪个更大
        if (sum2 > sum1) {
            sum1 = sum2;
        }

        // sum2 是包含最后一栋房子的方案， 
        // 每向后增加一栋房子，就是前一步的 sum1（不包含 lastIndex - 1 ） 
        // 加上当前 lastIndex 栋房子的金钱
        sum2 = tmp + nums[lastIndex]; 
    }

    return sum1 > sum2 ? sum1 : sum2;
};
```
再复杂的动态规划问题，都可以通过这三步来解决。难点在于第一步，即将问题分解成最优子问题。找到了最优子问题，问题就解决了一大半。第二步不过是将第一步的思路用递归代码表述出来；至于第三步递归转迭代，毕竟有递归的基本逻辑可以参考，多加练习可以较熟练的掌握。


