### 解题思路
hashTable思路
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
### 代码

```javascript
const containsNearbyDuplicate = (nums, k)=>{
    let obj={};
    for(let i=0;i<nums.length;i++){
        if(obj[nums[i]]){
            let temp=obj[nums[i]];
            if(Math.abs(i-temp[temp.length-1])<=k){
                return true;
            }else{
                obj[nums[i]].push(i);
            }
        }else{
            obj[nums[i]]=[i];
        }
    }
    return false;
};
```