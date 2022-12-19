假设数组长度为length，
1、先判断length-1元素能否跳到最后一个元素，如果能记录下来
2、在判断length-2元素能否调到最后一个元素，如果能记录下来
3、依次迭代，判断length-n元素能否跳到最后一个元素

那么，如何判断length-n元素能否跳到最后一个元素呢？
首先，根据前面描述，我们是知道length-n后面的元素是否能跳到最后元素的，因此，我们只需要判断length-n能否跳到length-n后面元素即可，
具体方式为，计算当前元素与记录中元素距离，如果当前元素值大于等于这个距离，说明可跳。

```
var canJump = function (nums) {
    if (nums.length <= 1) return true;
    let len = nums.length;
    let i = len - 1;
    let res = [];
    let map = {};
    while (--i >= 0) {
        let temp = nums[i];
        let distance = len - i - 1;
        res.some(item => {
            if (item - i <= temp) {
                map[i] = true;
                return true;
            }
        });

        if (!map[i] && temp >= distance) {
            map[i] = true;
        }
        if (map[i]) {
            res.unshift(i);
        }

    }
    return !!map[0];
};
```
