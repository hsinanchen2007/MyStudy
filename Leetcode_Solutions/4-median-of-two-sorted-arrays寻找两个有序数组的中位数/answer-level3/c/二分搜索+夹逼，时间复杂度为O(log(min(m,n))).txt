### 解题思路
二分搜索+双指针，相当于找第k小数

时间复杂度为O(log(min(m,n)))

核心思路为夹逼，判断是否查找结束会比切割要复杂

如何用切割实现可以参照[https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/]()

主要用来自己总结思路，上面链接的实现更优雅

## 详细分析
首先记两数组分别为a1与a2，长度对应为len1与len2

为了简化逻辑，我们默认len1<len2

看到要求log(m+n)的时间复杂度首先想到二分搜索。因为有两个数组，我们选择对长度较短的a1设置一个指针(a1+index1)进行二分搜索，然后在a2中设置另一个指针(a2+index2)。

我们需要使用这两个指针来划分出一半的小于min(a1[index1],a2[index2])的数与一半的个大于max(a1[index1],a2[index2])的数,即：
```python
half = (len1+len2-1)/2
index2 = half - index1
```

在保证index1与index2之间的关系后，只需对两个指针进行夹逼，即：

若a1[index1] > a2[index2]，则a1向左搜索；否则，a1向右搜索

当找到合并后数组的中间两项时，搜索结束

## 搜索结束条件
在夹逼的时候需要注意：我们将两个指针分别设置在了两个数组中，但是合并后数组的中间两项可能来自同一数组中，如：
```python
a1 = [1,4]
a2 = [2,3]
a0 = [1,2,3,4]
```
因此我们只能保证其中一个指针的位置，这里我们选择以所指数较小的指针作为结束搜索的判断依据，即：

**若*p1 < *p2, 则当p2左侧所有数都比*p1小搜索结束**

此时所有p1, p2左侧的数都比*p1小；所有p1, p2右侧的数都比 *p1大

因此*p1即a0[(len1+len2-1)/2]

```
bool checkFinish(int* nums1, int index1, int nums1Size, int* nums2, int index2, int nums2Size){
    if(nums1[index1] > nums2[index2]){
        if(index1 == 0 || index2 == nums2Size-1){
            return true;
        }
        if(nums1[index1-1] <= nums2[index2]){
            return true;
        }
        return false;
    }else{
        if(index2 == 0 || index1 == nums1Size-1){
            return true;
        }
        if(nums2[index2-1] <= nums1[index1]){
            return true;
        }
        return false;
    }
}
```
## 特殊情况
还是由于我们把指针分别放置在了两个数组中，所以如果较短的数组中所有数均小于(大于)中位数，则无法进行夹逼。此时我们可以直接根据较短数组长度直接得到中位数在另一数组中的位置。






### 代码

```c
int myMin(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

double avg(int a1, int a2){
    return ((double)a1 + a2)/2;
}

bool checkFinish(int* nums1, int index1, int nums1Size, int* nums2, int index2, int nums2Size){
    if(nums1[index1] > nums2[index2]){
        if(index1 == 0 || index2 == nums2Size-1){
            return true;
        }
        if(nums1[index1-1] <= nums2[index2]){
            return true;
        }
        return false;
    }else{
        if(index2 == 0 || index1 == nums1Size-1){
            return true;
        }
        if(nums2[index2-1] <= nums1[index1]){
            return true;
        }
        return false;
    }
}

double findMedianSortedArrays1(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *numTemp, numTempSize;
    int length = nums1Size + nums2Size;
    int half = (length-1)/2;
    if(nums1Size > nums2Size){
        numTemp = nums1;
        nums1 = nums2;
        nums2 = numTemp;
        numTempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = numTempSize;
    }
    if(nums1Size == 0){
        return nums2[half];
    }
    //nums1最大值小于中位数
    if(nums1[nums1Size-1] <= nums2[half-nums1Size]){
        return nums2[half-nums1Size];
    }
    //nums1最小值大于中位数
    if(nums2[half]<=nums1[0]){
        return nums2[half];
    }
    int bound1 = nums1Size/2, bound2 = half-bound1;
    int span = (bound1+1)/2;
    while(!checkFinish(nums1, bound1, nums1Size, nums2, bound2, nums2Size)){

        if(nums1[bound1] < nums2[bound2]){
            bound1 += span;
            bound2 -= span;
            span = (span+1)/2;
        }else{
            bound1 -= span;
            bound2 += span;
            span = (span+1)/2;
        }

    }
    return myMin(nums1[bound1],nums2[bound2]);
}

double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *numTemp, numTempSize;
    int length = nums1Size + nums2Size;
    int half = (length-1)/2;
    if(nums1Size > nums2Size){
        numTemp = nums1;
        nums1 = nums2;
        nums2 = numTemp;
        numTempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = numTempSize;
    }
    //nums1最大值小于中位数
    if(nums1Size == 0){
        return avg(nums2[half], nums2[half+1]);
    }
    if(nums1Size != nums2Size){
        if(nums1[nums1Size-1] <= nums2[half-nums1Size]){
            return avg(nums2[half-nums1Size], nums2[half-nums1Size+1]);
        }
        //nums1最小值大于中位数
        if(nums2[half+1] < nums1[0]){
            return avg(nums2[half], nums2[half+1]);
        }
    }
    int bound1 = nums1Size/2, bound2 = half-bound1;
    int span = (bound1+1)/2;
    while(!checkFinish(nums1, bound1, nums1Size, nums2, bound2, nums2Size)){

        if(nums1[bound1] < nums2[bound2]){
            bound1 += span;
            bound2 -= span;
            span = (span+1)/2;
        }else{
            bound1 -= span;
            bound2 += span;
            span = (span+1)/2;
        }
    }
    if(nums1[bound1] < nums2[bound2]){
        if(bound1 < nums1Size-1 && nums1[bound1+1] < nums2[bound2]){
            return avg(nums1[bound1], nums1[bound1+1]);
        }else{
            return avg(nums1[bound1], nums2[bound2]);
        }
    }else{
        if(bound2 < nums2Size-1 && nums2[bound2+1] < nums1[bound1]){
            return avg(nums2[bound2], nums2[bound2+1]);
        }else{
            return avg(nums1[bound1], nums2[bound2]);
        }
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if((nums1Size + nums2Size)%2){
        return findMedianSortedArrays1(nums1, nums1Size, nums2, nums2Size);
    }else{
        return findMedianSortedArrays2(nums1, nums1Size, nums2, nums2Size);
    }
}
```