思路：两次循环
    第一次循环：将数据添加到map中去，键为每一项的值，值为每一项的下标索引，索引是存在数组中添加到map中去
    第二次循环：使用target-nums[i],如果map中存在这一项,返回下标数组。
```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let len = nums.length,
        map = new Map();
    for(let i = 0;i<len;i++){
        if(!map.has(nums[i])){
            map.set(nums[i],[i]);
        }else{
            map.get(nums[i]).push(i);
        }
    }
    let flag= [];
    for(let i = 0;i<len;i++){
        if(map.get(nums[i]).length===2){
            if(nums[i]*2===target){
                flag = map.get(nums[i]);
                break;
            }
        }
        if(map.has(target-nums[i])&&(map.get(target-nums[i]))[0]!==i){
            flag.push(i);
            flag.push(map.get(target-nums[i])[0]);
            break;
        }
    }
    return flag;
};
```
