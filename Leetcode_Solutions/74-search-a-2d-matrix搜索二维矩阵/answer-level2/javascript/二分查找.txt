### 解题思路
 * 初步考虑如下，首先搜索出在哪一行，然后用二分查找寻找该行中是否有
 * 时间复杂度 O(m+logn);
 * opt1：如果查找区间也用二分法查找
 * 此时时间复杂度变成：O(logM+logN)=O(logMN);
 * 空间复杂度为：O(1)

### 代码

```javascript
const searchMatrix = (matrix, target)=>{
    if(matrix.length===0) return false;
    let m=matrix.length,n=matrix[0].length,temp=0;
    if(n===0) return false;
    let min=0,max=m-1;
    while(min<=max){
        let mid=Math.floor((min+max)/2);
        if(matrix[mid][n-1]>=target){
            max=mid-1;
        }else if(matrix[mid][n-1]<target){
            min=mid+1;
        }
    }
    // 处理边界：target比matrix中的每个值都大，min>m-1的情况要另外处理
    if(min>m-1) min=m-1;
    temp=min;
    // 处理边界：target比matrix中的每隔值都小
    if(matrix[temp][n-1]<target) return false;
    // console.info('temp==>',temp);
    const search=(arr,tgt)=>{
        let left=0,right=arr.length-1;
        while(left<=right){
            let mid=Math.floor((left+right)/2);
            if(arr[mid]===tgt){
                return true;
            }else if(arr[mid]>tgt){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return false;
    };
    return search(matrix[temp],target);
};
```