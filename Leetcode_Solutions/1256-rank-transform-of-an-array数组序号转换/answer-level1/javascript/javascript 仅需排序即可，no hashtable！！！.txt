首先生成一个$0,\cdots,n-1$的数组ind，然后对该数组排序，arr[i]越小i越靠前。
排完可知道，arr[ind[0]]是最小的数,则将结果中ans[ind[0]]设为1， arr[ind[1]]为次小数，若与arr[ind[0]]相等，则ans[ind[1]]也为1，否则为2，结果中其他数以此类推。

```
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var arrayRankTransform = function(arr) {
    let ind=Array(arr.length);
    for(let k=0; k<arr.length; k++)
        ind[k] = k;
    let ans=Array(arr.length);
    ind.sort((i1,i2)=>arr[i1]-arr[i2]);
    ans[ind[0]]=1;
    for(let k=1; k<arr.length; k++)
        if(arr[ind[k]]!=arr[ind[k-1]])
            ans[ind[k]]=ans[ind[k-1]]+1;
        else
            ans[ind[k]]=ans[ind[k-1]];
    return ans;

};
```