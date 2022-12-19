* 方法1:哈希表
```javascript
/**
 * 使用key-value存储的方式
 * 时间复杂度最差为O(n)
 * 空间复杂度最差为O(n)
 * @param nums
 * @returns {boolean}
 */
const containsDuplicate = (nums)=>{
    let obj={};
    for(let i=0;i<nums.length;i++){
        if(obj[nums[i]]){
            return true;
        }else{
            obj[nums[i]]=1;
        }
    }
    return false;
};

```

* 方法2:es6新数据结构Set


```javascript
// 一行代码，较简单
const containsDuplicate = nums=>!(nums.length===[...new Set(nums)].length);
```
