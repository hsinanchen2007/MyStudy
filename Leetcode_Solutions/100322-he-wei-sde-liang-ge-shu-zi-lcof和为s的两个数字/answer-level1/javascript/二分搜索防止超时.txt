### 解题思路
1. 拿出第n个元素a[n], 然后获取差值d=target-n
2. 在数组内用二分法寻找d

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    function bs(arr, what){
        const midp = Math.floor(arr.length/2);
        if(midp==0)return false; //数组排除完毕仍然没找到返回false
        const midv = arr[midp];
        if(what == midv)return true; //否则返回true
        if(what>midv){
            return bs(arr.slice(midp, arr.length), what); //排除掉左边
        }else{
            return bs(arr.slice(0, midp), what); //排除掉右边
        }
    }
    
    let p=0, l=nums.length;
    while(p<l){
        const ele = nums[p];
        const wanted = target-ele; //获取差值，如[1,2,3]目标为4, 差值=4-1=3 
        if(wanted>nums[l-1]){ //如果差值比最大的那个数字还要大，说明当前的数字不是，继续往下寻找
            p++;
            continue;
        }
        if(bs(nums, wanted))return [ele, wanted]; //二分搜索
        p++;
    }
    return [];
};
```