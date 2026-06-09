# 回溯法
枚举法最接近与朴素想法，回溯就是使用递归列举所有可能性

```
var canJump = function(nums) {
       return recursion(0,nums)
    };

    function recursion(i,nums) {
        if (i>=nums.length-1) {
            return true
        }
        for (let j = 1; j <= nums[i]; j++) {//从第一步开始往nums[i]走
            if (recursion(i+j,nums) ) {//若下一步能成功到达目的地则返回true,否则继续走其他步数
                return true
            }         
        }
        return false//走完所有步伐都没走通
    }
```
# 超时了，开始优化
通过样例执行链路发现
[3,2,1,0,4]=>3-2-1-0-0-1-0-0在3位置[坐标为0]上都走不通
通过给的样例也知道，第一次应该从最大步开始走出去

```
var canJump = function(nums) {
       return recursion(0,nums)
    };

    function recursion(i,nums) {
        if (i>=nums.length-1) {
            return true
        }
        for (let j =nums[i]; j >= 1; j--) {
            if (recursion(i+j,nums) ) {
                return true
            }         
        }
        return false
    }
```
还是超时了
[3,2,1,0,4]=>3-0-1-0-2-0-1-0在3位置上[坐标为0]都走不通

# 动态规划
```
var visit=[]//记录走不通的节点，防止重复再走

    var canJump = function(nums) {
       visit=[]
       return recursion(0,nums)
    };

    function recursion(i,nums) {
        if (i>=nums.length-1) {
            visit[i]=true
            return true
        }
        for (let j =nums[i]; j >= 1; j--) {
            if (visit[i]!=false&&recursion(i+j,nums) ) {
                return true
            }         
        }
        visit[i]=false
        return false
    }
```
# 贪心算法

从右到左，也是动态规划的自底向上方式

观察每个点是否能到达，并标记出此时距离，再往前观察
```
  var canJump = function (nums) {
        var instance = nums.length - 1//没有和1一个都满足，从自己编码可以看出
        for (let i = nums.length - 2; i >= 0; i--) {
            const e = nums[i];
            if (nums[i] + i >= instance) {//每个点都得判断
                instance = i
            }
        }
        return instance == 0
    };
```

从左到到右
```
var canJump = function (nums) {
        if (nums.length - 1 <= 0) {
            return true
        }
        var len = nums.length
        for (let i = 0; i < len - 1; i++) {
            const e = nums[i];
            if (e + i >= len - 1) {//某个点能到
                if (i == 0) {
                    return true
                }
                len = i+1//当前长度
                i = -1//重置回到0位置
            }
        }
        return false
    };

```
# 分治算法
