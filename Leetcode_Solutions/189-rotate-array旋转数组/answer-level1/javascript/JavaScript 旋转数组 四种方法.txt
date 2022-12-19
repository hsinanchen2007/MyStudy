解一：
> 数组拼接。

```js
var len = nums.length;
    k = k%len;
    var newNums = nums.concat(nums);
    newNums = newNums.slice(len-k,2*len-k);
    for (var i=0;i<len;i++){
        nums[i]=newNums[i];
    }
    return nums
```

解二：
> 每次右移1位，移k次。

```js
var rotate = function(nums, k) {
    for(var i=0;i<k;i++){
        var temp = nums[nums.length-1];
        for (var j=0; j<nums.length; j++){
            var tmp = nums[j];
            nums[j] = temp;
            temp = tmp;
        }
    }
    return nums
};
```

解三：
> 从位置0开始移，每次移动k个位置，移动后计算下一个位置。

```js
var rotate = function (nums, k) {
    k %= nums.length;
    if (k) {
        var len = nums.length;
        var start = 0; //开始位置
        var i = 0; //当前位置
        var temp = nums[len - k]; //当前位置的新值
        var count = 0; //已经操作了多少个元素，作为判断是否继续循环的条件

        while (count !== len) {
            var tmp = nums[i]; //保存当前位置的初始值，之后赋给temp
            nums[i] = temp; //将当前位置赋予新值
            temp = tmp; 
            i = (i + k) % len; //计算下个位置
            if (i === start) { //如果下个位置又回到起点
                i = ++start; 
                temp = nums[len - k + start]
            }
            count++;
        }
    }
    return nums
};
```

解四：
> 数组反转。第一次整体反转，第二次反转左边k个元素，第三次反转右边剩余元素。

```js
var rotate = function (nums, k) {
    var len = nums.length;
    k %= len;
    const reverse = function (arr,start,end) {
        while(start<end){
            var temp = arr[start];
            nums[start++]=nums[end];
            nums[end--]=temp;
        }
    };

    reverse(nums,0,len-1);
    reverse(nums, 0,k-1);
    reverse(nums,k,len-1)

    return nums;
};
```