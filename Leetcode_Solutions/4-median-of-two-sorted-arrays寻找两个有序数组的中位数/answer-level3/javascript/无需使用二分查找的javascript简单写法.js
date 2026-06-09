# 标题  查找有序数组的中位数,并不需要使用二分查找 ,简单通过数组下标运算，便可以求出

 **执行用时 :
164 ms
, 在所有 JavaScript 提交中击败了
94.29%
的用户
内存消耗 :
38.9 MB
, 在所有 JavaScript 提交中击败了
91.62%
的用户**
(不过有点小问题,最后我会说)

**下面是求中位数的函数**
1. function median(arr,size){
   let n = Math.ceil(size/2)-1;//向上取整
    if(size%2!==0){
        return arr[n]
    }else{
        return  (arr[n]+arr[n+1])/2;
    }
 }

**当然为了解决本题, 仅仅知道求中位数的不够的, 还得把2个有序数组合并为一个同样是有序的数组**
*下面给出函数*

2. function MergeArray(nums1,nums2){
    let arrSum=new Array(nums1.length+nums2.length);
    nums1[nums1.length]=100000;
    nums2[nums2.length]=100000;
    let i=0,j=0,k=0;
    while(k<arrSum.length){
        if(nums1[i]>=nums2[j]){
            arrSum[k]=nums2[j];
            j++;
            if(j==nums2.length){
                j=j-1;
            }
        }
        else if(nums1[i]<=nums2[j]){
            arrSum[k]=nums1[i];
            i++;
            if(i==nums1.length){
                i=i-1;
            }
        }
        k++;
    }
    return arrSum;
}

**最终函数**
function MergeArray(nums1,nums2){
    let arrSum=new Array(nums1.length+nums2.length);
    let n=Math.floor(arrSum.length/2);
    nums1[nums1.length]=100000;
    nums2[nums2.length]=100000;
    let i=0,j=0,k=0;
    while(k<arrSum.length){
        if(nums1[i]>=nums2[j]){
            arrSum[k]=nums2[j];
            j++;
            if(j==nums2.length){
                j=j-1;
            }
        }
        else if(nums1[i]<=nums2[j]){
            arrSum[k]=nums1[i];
            i++;
            if(i==nums1.length){
                i=i-1;
            }
        }
        k++;
    }
    if(arrSum.length%2===0){
        return (arrSum[n]+arrSum[n-1])/2
    }else{
        return arrSum[n];
    }
}

**解释**
**其实,最终的函数定义,有点类似于c中的双指针,即设置2个指针,指向2个数组的开头,再从头比较2个数组的值,把更小的那个值,存入合并的数组中,并且指针向前移动一位,即更大的值指针不变,再进行下一次循环时，仍然拿那个值去比较**

*当然这个算法最终会有一个bug,即2个数组中最大的那个数字无法被存入到合并的数组中,这是因为我们把2个数组中相比较后,更小的那个值存到合并数组中,
而最大的值自然和谁比都大*
*解决这个bug,我仅仅只想到了一种方法(如果有更好的方法,请告诉我),即我们可以把2个数组的最后增加一个Math.max(),
即  nums[nums.length]=Math.max()   当然最大值只能增加设置 , 我在本题中设置为  100000*
