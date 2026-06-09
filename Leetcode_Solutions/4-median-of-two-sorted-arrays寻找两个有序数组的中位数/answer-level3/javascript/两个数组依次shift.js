```
var findMedianSortedArrays = function(nums1, nums2) {
    let contactArr=[]
    let totalLength=(nums1.length+nums2.length)
    let num1=nums1.shift()
    let num2=nums2.shift()
    for(let i=0;i<totalLength;i++)
    {    
        if(num1<=num2||num2===undefined)
            {
                contactArr.push(num1)
                num1=nums1.shift()
            }
        else{
                contactArr.push(num2)
                 num2=nums2.shift()
        }
    }
    
    //console.log('输出contactArr',contactArr);
    if(totalLength%2===1)
        return (contactArr[(totalLength+1)/2-1]).toFixed(5)
    else
        return ((contactArr[totalLength/2-1]+contactArr[totalLength/2])/2).toFixed(5)
};
```
