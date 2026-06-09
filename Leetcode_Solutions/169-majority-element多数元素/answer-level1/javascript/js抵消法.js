

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let res=nums[0];//存储结果
    let cnt=1;          //记录结果值多出的次数
    for(let i=1;i<nums.length;i++){

        if(res==nums[i]){//结果值如果和遍历的当前值相等，则cnt++
            cnt++;
        }
        else if(cnt>0){//结果值如果和遍历的当前值不相等，cnt--
            cnt--;
        }else{          //结果值如果和当前值不等，且结果值多出的次数已经为0了
            res=nums[i];//更新结果值
            cnt=1;
        }
    }
    return res;
};
```