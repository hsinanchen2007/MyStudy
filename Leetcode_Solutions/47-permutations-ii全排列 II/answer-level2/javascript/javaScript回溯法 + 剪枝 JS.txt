![image.png](https://pic.leetcode-cn.com/529f15aaa9356eb692cd4034a1ce9a9be8a8c908a184c1779c76829532c742b7-image.png)
这个题目和46是一样的，只是多了去重的步骤，专业名词叫“剪枝”
直接看代码吧，注释写在代码里，希望各位大佬多多提可以改进的意见
```
var permuteUnique = function(nums) {
    // 递归回溯算法，依次取aries里面的值，放到temp中，当aries为空的时候，则找到了一种解法
    var backstack = function( aries, temp ) {
        // 如果本次传进来的aries为空，说明已经找到了一种解法
        if ( aries.length === 0 ) {
            // 这里直接把这种解 push 到结果集中，去重不在这里，请向下看
            // 这里的深拷贝就不解释了，相信做到这一题的你是明白的
            res.push( JSON.parse( JSON.stringify( temp ) ) );
        }
        // aries里面还有值，说明当前解法的寻找还没有完成，继续
        else {
            for ( let i in aries ) {
                // 如果当前要取的值和上一个值是相同的，那么跳过本次索引i的这个数，找下一个数
                if ( i > 0 && aries[i] === aries[i - 1] ) {
                    continue;
                }
                // 本次值与上一个值不同，可以使用
                else {
                    temp.push( aries[ i ] ); // 把当前值扔到未完成的解法中
                    backstack( aries.slice( 0, i ).concat( aries.slice( +(i) + 1 ) ), temp ); // 剩下的值拼成一个数组，继续递归
                }
            }
        }
        if ( temp.length === 0 ) return ; // 如果temp 为空，说明此次递归已经找到一种解法并且已经push 到了结果集中
        temp.pop(); // 如果还没有找到一种解法，那么把最后一个值pop 掉，继续寻找其他解法
    };
    
    let res = []; // 承载最终结果集的数组
    nums.sort( (a,b) => a - b ); // 先排序，为了在回溯的过程中判断去重
    backstack( nums, [] ); // 执行回溯算法
    return res;
};
```
