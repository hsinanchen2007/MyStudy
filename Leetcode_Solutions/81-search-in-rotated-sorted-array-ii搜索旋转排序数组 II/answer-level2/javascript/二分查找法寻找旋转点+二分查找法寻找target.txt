### 解题思路
因为javascript是动态变量类型的语言，即运行时确定数据类型，因此必须用``Math.floor``或者``Math.ceil``控制
key1: 不能让mid和left一样的时候移动left，不然此时会发生像[3,1]这种无法通过的情况
key2: arr[mid]=arr[left]的情况要移动left而不是移动right

### 代码

```javascript
const search = (nums, target)=>{
    if(nums.length===0) return false;
    if(nums.length===1) return nums[0]===target;
    const find=arr=>{
        let left=0,right=arr.length-1;
        while(left<=right){
            let mid=Math.floor((left+right)/2);
            // 因为mid取的是floor
            if(arr[mid]===arr[left]&&mid!==left){
                // key1: 不能让mid和left一样的时候移动left，不然此时会发生像[3,1]这种无法通过的情况。究其原因是mid取floor的缘故
                left+=1;
                continue;
            }
            if(arr[mid]===arr[right]){
                right-=1;
                continue;
            }
            if(arr[mid]>arr[mid+1]){
                return mid;
            }else {
                if (arr[mid] >= arr[left]) {
                    // key2: arr[mid]=arr[left]的情况要移动left而不是移动right。究其原因是mid取floor的缘故
                    left=mid+1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return left;
    };
    const search0=(left,right)=>{
        while(left<=right){
            let mid=Math.floor((left+right)/2);
            if(nums[mid]===target){
                return true;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return false;
    };
    let idx=find(nums);
    // console.info('idx',idx);
    return (search0(0,idx)||search0(idx+1,nums.length-1));
};
```