楼主一开始接触到这题的各位大佬的解法后, 感觉这类解法思路的确很好, 就是先排序, 然后双指针的思路,
在这就不详述了,  可想了想, 还是想从暴力解法试试, 踩踩坑, 这样才能对比出 成熟解法的高效,优点
我也相信 这种成熟解法也是人们在尝试暴力解法后, 踩坑之后, 一步一步优化出来的, 

最初楼主是不太明白为何一定要先给数组排序的, 尝试完暴力解法后, 发现先给数组排好序是最简便的处理去重的方法
上代码:
```
var threeSum1 = function(nums) {
    //示例 nums:  [-1, -1, 0, 1, 2, -1, -4]
    let res = [];
    //不得不一开始就给数组排序, 这样好去掉重复的三元组
    //不然就会出现这种情况: [ -1, 0, 1 ], [ 0, 1, -1 ],  还是得排序后去重
    //排好序后, 重复的元素一定在一起, 当和前边的数相等时, 说明这个数已经查找过了, 就不必查找了
    // nums.sort((a, b) => a - b);  // 测试时, 别忘打开排序

    for (let i = 0; i < nums.length; i ++ ) {
        for (let j = i + 1; j < nums.length; j ++) {
            for (let k = j + 1; k < nums.length; k ++) {
                //在一开始nums没有排序的情况下, 发现做了这些处理后, 依然无法完全避免 重复的三元组
                if ( i > 0 && nums[i] == nums[ i - 1] ) continue;
                if ( j > i + 1 && nums[j] == nums[ j - 1] ) continue;
                if ( k > j + 1 && nums[k] == nums[ k - 1] ) continue;
                
                //如果在这里给 符合条件的三个数排序, 然后对比去重符合条件的 三元组, 这样更复杂了
                //所以最后发现在 一开始给整个数组排序还是比较简单的, 复杂度低的
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push([ nums[i], nums[j], nums[k] ]);
                };
            }
        }
    };

    return res;
};
```


**排序, 双指针解法 **

```
var threeSum2 = function(nums) {
    let res = [];
    nums.sort((a, b) => a - b); // 排序
    if (nums == null || nums.length < 3) {
        return res;
    };
    if (nums[0] > 0 || nums[nums.length - 1] < 0) {
        return res;
    };
    //这时 nums 数组已经是排好序的
    for (let k = 0; k < nums.length; k ++) {
        //最左侧的数大于 0 , 那么后边两个数也必然大于 0 , 三数之和必然大于 0, 
        //所以不符合条件
        if (nums[k] > 0)  break;
        
        // 相等的, 跨过去, 不然这样, 最后的结果中会有重复的三元组
        if ( k > 0 && nums[k] == nums[k - 1]) continue;
        
        //双指针, 不断缩小
        let i = k + 1;
        let j = nums.length - 1;

        while ( i < j ) {
            let sum = nums[k] + nums[i] + nums[j];
            if (sum == 0 ) {
                res.push([ nums[k], nums[i], nums[j] ]);
                while(i < j && nums[i] == nums[ ++i ]);
                while(i < j && nums[j] == nums[ --j ]);
            } else if ( sum > 0 ) {
                //大于 0, 我们就让 j -- 
                while(i < j && nums[j] == nums[ -- j]);
            } else { //sum < 0 
                //小于 0 , 我们就让 i ++, 因为这些都是排好序的数组
                while(i < j && nums[i] == nums[ ++i]);
            }
        };
    };
    return res;
};

```
