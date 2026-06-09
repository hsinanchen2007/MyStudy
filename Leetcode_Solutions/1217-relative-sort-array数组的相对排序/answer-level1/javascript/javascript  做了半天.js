
![image.png](https://pic.leetcode-cn.com/de441f74858652abdd203ae193e107d65f0991e4a5a08c25526c3d41736eb8f0-image.png)
做了半天
思路：先得到arr1在arr2里的index，把相同的数放在同一个数组，最后展开数组
var relativeSortArray = function(arr1, arr2) {
    var array=[]
    var result=[]
    var l=arr2.length
<!-- 创建最后数组 -->
    array[l]=[]
    for(var i in arr1)
        {
            var a=arr2.indexOf(arr1[i])
            if(a>-1)
                {   if(!array[a])
                    {
                        array[a]=[]
                        array[a].push(arr1[i])
                    }
                 else{
                    array[a].push(arr1[i])
                 }
                }
            else{
                array[l].push(arr1[i])
            }
        }
    array[l].sort(function(a,b){return a-b})
    for(var i in array)
        {
            result.push(...array[i])
        }
    return result
};