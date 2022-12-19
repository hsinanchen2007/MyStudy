### 解题思路
1. 第一层循环数组，索引b，如果碰到一个0，停止
2. 启动第二层循环，索引为b+1, 也就是从下一个位置开始搜索一个不为0的数字
3. 搜索到了就替换掉这俩元素
4. 检查是否已经到了末尾，到的话就返回

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let b=0, l=nums.length;
    if(!l || l==1)return;
    while(b<l){
        const ele = nums[b];
        if(ele){
            b++;
            continue; //如果不为0，继续寻找
        }
        let p = b+1; //找到一个0，停止，然后从下一个位置开始寻找一个不为0的数字来替换
        while(p<l){
            const rep = nums[p];
            if(rep){ //找到了，实施替换
                nums[b]=rep;
                nums[p] = ele;
                break; //然后退出让外层循环的第一个指针继续找0
            }
            p++; //没找到，继续找
        }
        if(p>=l)break;
    }
};
```