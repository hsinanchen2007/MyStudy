```
    var nums1 = [2,4]
    var nums2 = [1,2,3,4]
    var arr = []
    for(var i=0; i<nums1.length; i++){
        var index = nums2.indexOf(nums1[i])+1
        var arrIn = []
        for(var j=index; j<nums2.length; j++){
            if(nums2[j]>nums1[i]){
                arrIn.push(nums2[j])
            }
        }
        if(arrIn.length>0){
            arr.push(arrIn[0])
        }else{
            arr.push(-1)
        }
    }
    console.log(arr)
```
  1. 遍历nums1中每个元素
  2. 找出其在nums2中的序号
  3. 从序号开始遍历nums2
  4. 找到第一个大的直接推入数组，无则推入-1

