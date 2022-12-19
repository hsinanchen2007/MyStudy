首先逆序对是只要当前数字大于之后数字即可，以7564举例，逆序对：75,76,74,54,64。

使用正常的冒泡排序时间复杂度为O(n^2)，而我们想要优化到O（nlogn），O（nlogn）的算法有快排、堆排、归并。

考虑本题的要求，归并排序最合适。为什么归并最合适，因为归并排序的时候，所分成的是两段数组，

第一段数组元素的初始下标一定是小于第二段数组元素的初始下标，之后要对两段数组进行合并

以7564举例：

初始下标:0123->1032
数组元素:7564->5746  
我们接下来要合并的是57和46，可以看到57的初始下标都小于46的初始下标。因此我们可以在排序比较中，判断逆序对的个数 

判断逆序对的方法：

当第二段数组元素出列时，计算逆序对。（这里出列代表加入新数组）
我们可以知道，当第二段数组中的元素出列时，代表当前元素小于了第一个数组中还未出列的所有元素，因此第一个数组中还未出列的所有元素都可以与第二个数组中的当前元素组成逆序对。

这里我再用一张图，可以更加清晰的看出判断逆序对的方法。
[来自我朋友liweiwei的题解](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/bao-li-jie-fa-fen-zhi-si-xiang-shu-zhuang-shu-zu-b/)

![image.png](https://pic.leetcode-cn.com/ea112362af0b14e24d7adfd57014a9cb2997499ffb70294b97e1fcf410532be1-image.png)

代码注释写的很清楚，具体详见注释。
完整代码
```java
class Solution {
    int res = 0;
    int[]nums;
    //中转数组
    int[]temp;
    public int reversePairs(int[] nums) {
        this.nums = nums;
        if(nums==null||nums.length==0)
            return 0;
        temp = new int[nums.length];
        mergeSort(0,nums.length-1);
        return res;
    }
    public void mergeSort(int start,int end)
    {
        if(start<end)
        {
            int mid = (start+end)/2;
            //对第一段数组进行归并
            mergeSort(start,mid);
            //对第二段数组进行归并
            mergeSort(mid+1,end);
            //对两段数组进行合并
            merge(start,mid,end);
        }
    }
    /*
    不光要合并还要计算逆序对
    */
    public void merge(int start,int mid,int end){
        int i = start;
        int j = mid+1;
        int t = 0;
        while(i<=mid&&j<=end)
        {
            //注意只有大于才是逆序对，等于不是逆序对，等于要放在else里执行。
            if(nums[i]>nums[j])
            {
                //第一个数组中的元素个数
                res+=mid-i+1;
                temp[t++] = nums[j++];
            }else{
                temp[t++] = nums[i++];
            }
        }
        //数组一中还有元素，说明这些元素是当前两个数组中最大的，但之前已经为他们构建过逆序对了(或者理解为我们只考虑第二个数组元素出列的情况)
        while(i<=mid)
        {
            temp[t++] = nums[i++];
        }
        //数组二中还有元素，说明这些元素是当前两个数组中最大的，因此前面的元素无法和他们构成逆序对
        while(j<=end)
        {
            temp[t++] = nums[j++];
        }
        t=0;
        while(start<=end)
            nums[start++] = temp[t++];
    }
}
```
