### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
//自带sort排序
// return nums.sort(function compare(a,b){
//      return a-b;
// })

    //冒泡排序
//     if(nums==null||nums.length<2){
//         return nums;
//     }
//    for(var i = nums.length-1;i>0;i--){
//        for(j = 0;j<i;j++){
//            if(nums[j]>nums[j+1]){
//                var temp = nums[j];
//                nums[j] = nums[j+1];
//                nums[j+1] = temp;
//            }
//        }
//    }
//    return nums;

//归并排序
// var length = nums.length;
// if(nums==null||nums.length<2){
//     return nums;
// }
// var mid = Math.floor(length/2);
// var left = nums.slice(0,mid);
// var right = nums.slice(mid,length);
// return merge(sortArray(left),sortArray(right));

// function merge(left,right){
//     var p1 = 0;
//     var p2 = 0;
//     var help = [];
//     var i = 0;
//     while(p1<left.length&&p2<right.length){
//         help[i++] = left[p1]<right[p2]?left[p1++]:right[p2++];
//     }
//     while(p1<left.length){
//         help[i++] = left[p1++];
//     }
//     while(p2<right.length){
//         help[i++] = right[p2++];
//     }
//     return help;
// }
   
   //堆排序
   //快速排序
   quickSort(nums,0,nums.length-1);
   return nums;
   function quickSort(arr,L,R){
       if(arr==null||arr.length<2){
           return arr;
       }
       if(L<R){
           //在L-R上随机选取一个数作为划分值
           var p1 = Math.floor(Math.random()*(R-L));
           //划分后的区间
           var p = partition(arr,L,R);
           quickSort(arr,L,p[0]-1);
           quickSort(arr,p[1]+1,R);
       }
       return arr;
   }
   function partition(arr,L,R){
       var less = L-1;
       var more = R;
       while(L<more){
           if(arr[L]<arr[R]){
               swap(arr,++less,L++);
           }else if(arr[L]>arr[R]){
               swap(arr,--more,L);
           }else{
               L++;
           }
       }
       swap(arr,more,R);
       return [less+1,more];
   }

   function swap(arr,i,j){
       var temp = arr[i];
       arr[i] = arr[j];
       arr[j] = temp;
   }
   
};
```