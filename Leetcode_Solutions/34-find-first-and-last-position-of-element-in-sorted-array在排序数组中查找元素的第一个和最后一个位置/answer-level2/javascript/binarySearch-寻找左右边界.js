### 解题思路
 * 从题意来看其实就是二分寻找左右边界值;
 * 时间复杂度为T(2logN)==>O(logN)
 * 空间复杂度为O(1)

### 代码

```javascript
const searchRange = (nums, target)=>{
    let left=0,right=nums.length-1,ll=0,rr=0;
    const findLeft=(left,right)=>{
        while(left<=right){
            let mid=Math.floor((left+right)/2);
            if(nums[mid]===target){
                right=mid-1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }
        }
        ll=left;
    };
    const findRight=(left,right)=>{
        while(left<=right){
            let mid=Math.floor((left+right)/2);
            if(nums[mid]===target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }
        }
        rr=right;
    };
    findLeft(left,right);
    findRight(left,right);
    if(rr>=ll){
        return [ll,rr];
    }else{
        return [-1,-1];
    }
};
```