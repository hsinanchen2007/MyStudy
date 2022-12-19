```
function partation (s, l , r)  {
    // // //这里的 l , r 是指整个数组的范围下的坐标
    // let mid = Math.floor( (l + r) / 2 );
    // //第一次先取 l, r, 中间的为基准值
    // let x  = s[mid];
    // s[mid] = s[r];
    // s[r] = x;
    // // x 要记录必须是首坑的值

    let x = s[r]; //要记录必须是首坑的值, 并以他为基准值
    let i = l; 
    let j = r;

    while (i < j ) {
        while ( i < j && s[i] <= x) {
            //小于 x的, 是所期望的, 都while循环掉, 找到大于的再处理
            i ++;
        }

        if(i < j) {        //其实刚开始是赋给最右侧了
            s[j] = s[i];  //将s[i]填到s[j]中，s[i]就形成了一个新的坑
            j --;
            //也可能这里j 就是等于i了, 跳出整个while, s[i]形成新坑
        }

        while ( i < j && s[j] > x ) {
            //大于 x的是所期望的, 都while 循环掉
            j --;
        }

        if (i < j) {
            s[i] = s[j];
            i ++;
        }
    }
    //跳出while循环一定是i == j , 
    //为什么这个时候, s[i] 就应该赋值为 原来的基准值呢
    //因为经过while循环,交换之后, i 之前的一定是小于这个基准值的
    //i 之后的是 由 j -- , 一个一个过滤过的, 是大于 这个基准值的
    //所以s[i] 一定为赋值为基准值, 并且 x 也是记录的首坑值
    s[i] =  x;
    return i;
}
function findKthLargest (nums, k) {

    let low = 0;
    let high = nums.length - 1;

    while ( low <= high ) {
        let i = partation (nums, low , high );
        let target =  nums.length  - k;
        if ( i < target ) {
            low = i + 1; //如果i < target, 证明要从 i 之后的值里开始找
        } else if ( i > target ) {
            high = i - 1; 
        } else  {
            // i == target
            return nums[i];
        }
    }
    return -1;
}

```