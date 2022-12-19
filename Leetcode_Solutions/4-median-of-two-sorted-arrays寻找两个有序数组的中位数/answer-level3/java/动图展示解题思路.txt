## 动图展示解题思路

### 1.1 有序数组合并再取中间元素

由于是两个有序数组，我们很容易通过O(n+m)的方式合并两个数组。合并后直接取中位数即可。

### 1.2 遍历所有可能的中位划分

中位数实际上是**将两个数组整体划分为元素个数相等的两个部分**，并且**前一个部分中的数都不大于后一个部分**。由于两个数组已经有序，因此“两个数组整体划分为元素个数相等的两个部分”的划分方式有且仅有**min(m,n)+1**种可能，我们只需判断每一种可能是否符合“前一个部分中的数都不大于后一个部分”即可，算法复杂度位**O(min(m,n)+1)**。每次划分都会划分出如动图中的绿色和蓝色两个部分。需要注意总数为奇数和偶数时中位数的计算方式，以及查找划分位置时数组越界处理。
![...0-01-28下午1.07.41.mov](d7295766-f995-4e7f-b7f3-48398cc1b68c)
![屏幕录制2020-01-28下午1.gif](https://pic.leetcode-cn.com/43d6276ce81ab22702c6fade0fee9609b02c5561d146fb3e0ef7ba0208d4ab8d-%E5%B1%8F%E5%B9%95%E5%BD%95%E5%88%B62020-01-28%E4%B8%8B%E5%8D%881.gif)

代码如下：

``` java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length1 = nums1.length < nums2.length ? nums1.length : nums2.length;
        int length2 = nums1.length < nums2.length ? nums2.length : nums1.length;
        //两个分组的大小，同样适用于取两个有序数组中的前k大/小的数
        int half = (length1 + length2) / 2;
        //判断较短的数组位numss1
        int[] numss1 = nums1.length < nums2.length ? nums1 : nums2;
        int[] numss2 = nums1.length < nums2.length ? nums2 : nums1;
        int part1max = 0;
        int part2min = 0;
        int j = 0;
        if(half == 0){
            return numss2[0];
        }
        // 防止数组是逆序的，该题的测试例中全部是顺序递增的，因此给注释掉了
        // if(numss1.length > 1){
        //     if(numss1[0] > numss1[1]){
        //         reverseArrray(numss1);
        //     }
        // }
        // if(numss2.length > 1){
        //     if(numss2[0] > numss2[1]){
        //         reverseArrray(numss2);
        //     }
        // }
        for(int i = 0; i < numss1.length+1;i++){
            j = half - i;
            if(i == 0){
                part1max = numss2[j-1];
            }else if(j == 0){
                part1max = numss1[i-1];
            }else{
                part1max = Math.max(numss1[i-1],numss2[j-1]);
            }
            if(i == numss1.length){
                part2min = numss2[j];
            }else if(j == numss2.length){
                part2min = numss1[i];
            }else{
                part2min = Math.min(numss1[i],numss2[j]);
            }
            if(part2min >= part1max){
                return (length1 + length2)%2 == 0 ? (part1max + part2min) / 2.0 : part2min;
            }
        }
        return (length1 + length2)%2 == 0 ? (part1max + part2min) / 2.0 : part2min;
    }
    private void reverseArrray(int[] nums){
        int temp;
        for(int i = nums.length-1; i >= nums.length / 2; i--){
            temp = nums[i];
            nums[i] = nums[nums.length-i-1];
            nums[nums.length-i-1] = temp;
        }
    }
}
```



* 时间复杂度 `O(min(m,n)+1)` 3ms，98.37%
* 空间复杂度`O(1)`

### 1.3 方法2加入二分法即可

由于方法二是由小到大遍历较小数组的所有插入位置，我们可以引入二分法进一步提高查找合适划分速度。取中间位置尝试进行划分，观察两个部分四个子数组的极值，向左向右缩小搜索范围。（详见官方题解）

算法复杂度为**O(log(min(m,n)+1))**，代码如下。

``` Java
class Solution{ //O(log(min(m,n)+1))
    public double findMedianSortedArrays(int[] nums1, int[] nums2){
        numsA = nums1.length <= nums2.length ? nums1 : nums2;
        numsB = nums1.length <= nums2.length ? nums2 : nums1;
        total = numsA.length + numsB.length;
        half = total / 2;
        isOdd = total % 2;
        return getMedianSortArrays(0,numsA.length);

    }
    private int[] numsA = null;
    private int[] numsB = null;
    private int total = 0;
    private int half = 0;
    private int isOdd = 0;
    private double getMedianSortArrays(int start, int end){
        int i = 0;
        int j = 0;
        if(start == end){
            i = start;
            j = half - i;
            if(isOdd == 0){
                int partAMAX = Math.max(i==0 ? Integer.MIN_VALUE : numsA[i-1],j == 0 ? Integer.MIN_VALUE : numsB[j-1]);
                int partBMIN = Math.min(i==numsA.length ? Integer.MAX_VALUE : numsA[i], j==numsB.length ? Integer.MAX_VALUE : numsB[j]);
                return (partAMAX + partBMIN) / 2.0;
            }else{
                int partBMIN = Math.min(i==numsA.length ? Integer.MAX_VALUE : numsA[i], j==numsB.length ? Integer.MAX_VALUE : numsB[j]);
                return partBMIN;
            }
        }
        i = (start + end) / 2;
        j = half - i;

        int partAMAX = Math.max(i==0 ? Integer.MIN_VALUE : numsA[i-1],j == 0 ? Integer.MIN_VALUE : numsB[j-1]);
        int partBMIN = Math.min(i==numsA.length ? Integer.MAX_VALUE : numsA[i], j==numsB.length ? Integer.MAX_VALUE : numsB[j]);
        if(partAMAX <= partBMIN){
            if(isOdd == 0){
                return (partAMAX + partBMIN) / 2.0;
            }else{
                return partBMIN;
            }
        }
        if(i==0){
            return getMedianSortArrays(i+1,end);
        }
        if(numsA[i-1] > numsB[j]){
            return getMedianSortArrays(start,i-1);
        }else {
            return getMedianSortArrays(i+1,end);
        }


    }
}
```

* 时间复杂度 `O(log(min(m,n)+1))`
* 空间复杂度`O(1)`
* 执行用时 3ms，98.37%


## 2. 解题收获

观察结果的特征，遍历所有可能结果，进一步考虑优化措施。