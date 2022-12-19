### 解题思路
1.首先想到，由于是求未出现的最小正整数，因此这个数值不会低于0，不会超过数组长度+1；
2.在不受限制情况下第一首先想到使用同等长度的哈希表存储当前表，但是由于额外空间只能为n，因此只能在遍历的时候将此数组更改为哈希表，即将数组的每个元素放到元素值对应的索引位置，从而将所有元素排序；
3.如何排序，遍历每个元素，将元素放到该元素值对应的索引位置，然后将索引位置的值拿出来存到临时变量，更改索引值i，再找到索引位置做同样的处理；元素值有三种情况：小于0或者大于数组长度的时候，删除该值，置为0或者临时变量存储的值；等于索引值的时候，不变；其他情况，即不等于索引值也未超出处理范围的时候，则继续找当前值得索引位置；直到所有符合条件的值都放在它应该在的位置；
4.根据排序好的表，找最小正整数；

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    //最后结果为：索引值 = 当前存储值 - 1。eg. nums[0] = 1,nums[1] = 2 ...
    var res = nums.length > 0 ? nums.length + 1 : 1,flag = 0,i = 0,tmp = 0;
    //遍历元素，索引大于数组长度，处理完成
    while(i < nums.length){
        //当前值不符合答案的时候
        if(nums[i]<1||nums[i]>nums.length) {
            //如果临时变量有值
            if(tmp){
                nums[i] = i + 1;
                tmp = 0;
                i = flag;
            }
            else nums[i++] = 0;
        }
        //当前值位置排序好的时候,即元素不需要动
        else if(nums[i] === i+1) {
            if(tmp){
                tmp = 0; i = flag;
            }else{
                i++;
            }
        }
        //其他情况
        else{
            //如果临时变量有值,继续处理当前值，放到它该放的位置
            if(tmp){
                tmp = nums[i];
                nums[i] = i + 1;
                i = tmp - 1;
            }
            //临时变量没有值，则记录当前位置，处理当前值放在它应该放的位置
            else{
                //记录当前位置，为了处理好所有值后，返回当前索引
                flag = i + 1;
                tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                //当前值不符合条件时候，不存储，正常处理下一个值
                if(tmp<1||tmp>nums.length){
                    tmp = 0; i++;
                }
                //更改索引
                else i = tmp - 1;
            }
        }
    }
    for(i = 0; i < nums.length; i++){
        if(nums[i] !== i+1) return i+1;
    }
    return res;
};
```