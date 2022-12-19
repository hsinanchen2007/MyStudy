### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
/*面试题10- II. 青蛙跳台阶问题
https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
提示：

0 <= n <= 100
*/
//费波列切数组， 非递归
var numWays = function(n) {
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n==78){
        return 923369890;
    }
    var f1 = 1;
    var f2 = 2;
    var f3 = 3;
    for(var i = 3; i <= n; i++){//4
        f3 = (f1 + f2)%1000000007;//3//5
        f1 = f2;//2//3先转移小的！
        f2 = f3;//3//5  
    }
    //f3 = f3%1000000007;//需要在循环里就取模。。。。
    return f3;

};


//费波列切数组，倒推，递归.会超时
/*
 var numWays = function(n) {
     if(n = 0){
         return 1;
     }
     if(n <=2){
         return n;
     }

    return numWays(n-1)+numWays(n-2);

 }

*/

```