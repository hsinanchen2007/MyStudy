

```javascript []
var findMedianSortedArrays = function (nums1, nums2) {
    //获取第一个数组的长度
    var l1 = nums1.length;

    //获取第二个数组的长度
    var l2 = nums2.length;
    //这个index是用来存储中位数的位置的，即中位数是整个数据中的第index个数
    //（偶数的话，则表示前面那个数是第几个数）
    var index;
    //判断总长度是否为偶数
    var isOu = (l1 + l2) % 2 == 0 ? true : false

    if (isOu) {
        //如果总长度是偶数，可以直接求出中位数的位置
        index = parseInt((l1 + l2) / 2);
    }
    else {
        //如果总长度不是偶数，则总长度+1后再除以二求得中位数的位置
        index = parseInt(((l1 + l2) + 1) / 2)
    }

    //res用来存储最终结果
    var res；

    //中位数的整个数组中的第index个数，这里的while循环执行index次会结束
    while (index--) {
        //已知数组排序是从小到大排序的，所以比较nums1和nums2的第一个元素的大小
        if (nums1.length != 0 && nums2.length != 0) {
            //取小的出来，然后通过.shift方法删除该值,并返回去掉的值给res
            res = nums1[0] < nums2[0] ? nums1.shift() : nums2.shift()
        }
        //如果nums1数据全部被删除，此时直接从nums2里取数据
        else if (nums1.length == 0 && nums2.length != 0) {
            res = nums2.shift()
        }
        //如果nums2数据全部被删除，此时直接从nums1里取数据
        else if (nums1.length != 0 && nums2.length == 0) {
            res = nums1.shift()
        }
        //执行完循环后，此时的res是整组数据里的最小值
        //当第二次循环的时候，res就是第二小的值
        //当第三次循环的时候，res就是第三小的值
        //当第四次循环的时候，res就是第四小的值
        //当第index次循环的时候，res就是第index小的
        //此时的res的值就是所有数据中位数了
        //(因为res是所有数据中第index小的数，也就是第index个数，而index正是中位数的位置)
    }

    //如果是总长度是偶数，需要让res加上下一个比他大的数，所以还要再执行一次上面的循环
    if (isOu) {
        if (nums1.length != 0 && nums2.length != 0) {
            res += nums1[0] < nums2[0] ? nums1.shift() : nums2.shift()
        }
        else if (nums1.length == 0 && nums2.length != 0) {
            res += nums2.shift()
        }
        else if (nums1.length != 0 && nums2.length == 0) {
            res += nums1.shift()
        }
        res /= 2;
    }

    return res;


};
```

