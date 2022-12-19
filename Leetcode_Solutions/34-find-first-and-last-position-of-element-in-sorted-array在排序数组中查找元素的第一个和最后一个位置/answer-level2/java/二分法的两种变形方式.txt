  如果不要求时间复杂度，只需要分别正序遍历找左边target和逆序遍历找右边target即可。但是根据题目要求的时间复杂度O(log n)，看出这依然是一个二分查找的变种。

## 思路一：二分法再线性法

1. 二分法找到target，如果不存在则返回[-1,-1]。
2. 如果nums[mid]==target，利用数组有序的特点， 以mid为中心分别向左向右线性查找，找到最左和最右的target值。

    
```java
public int[] searchRange(int[] nums, int target) {
        int[] result={-1,-1};
        int left=0,right=nums.length-1;
        //先二分法找到target的下标
        while (left<=right){
            int mid=(left+right)/2;
            //如果找到target的下标mid，就以mid为中心分别向左向右线性查找
            if (nums[mid]==target){
                int left_key=mid,right_key=mid;
                //向左向右线性查找，直至找到不等于target
                while (left_key>=0&&nums[left_key]==target)left_key--;
                while (right_key<nums.length&&nums[right_key]==target)right_key++;
                //保存最左和最右的target值的下标
                result[0]=left_key+1;
                result[1]=right_key-1;
                //终止二分法
                break;
            }else if (nums[mid]<target){
               left=mid+1;
            }else if (nums[mid]>target){
                right=mid-1;
            }
        }
        return result;
    }
```

最坏情况，有序数组中元素都等于target，例如target=8，[8,8,8,8,8,8]，则线性寻找最左最右时需要遍历每个元素。所以时间复杂度是：O(n)。但是因为测试数据的关系，leetcode中这种思路也是可以通过的。

## 思路二：直接二分法分别查找

嘴笨，说的比较抽象，其实根据下述方法，动笔在纸上画一画模拟一下就很清晰明了了。

1. 二分法查找最左target：如果中间值(nums[mid])不等于target，则根据情况移动left或者right来减半搜索区间范围即可。需要改变的是：当中间值等于target，不能直接返回，而是要收缩right减小搜索区间继续逐步锁定最左的target。
   最终得到的left(因为循环终止条件时right==left，所以最终left和right是相等的)可以理解成：数组中比target小的元素的个数。所以最终进行简单的判断即可，如果'left==nums.length'说明所有的数都比target小则返回-1，如果'nums[left]==target'则nums[left]就是最左的target，否则数组中没有target返回-1。
2. 二分法查找最右target：如果中间值(nums[mid])不等于target，则根据情况移动left或者right来减半搜索区间范围即可。需要改变的是：当中间值等于target，不能直接返回，而是要增加left减小搜索区间继续逐步锁定最右的target。
   因为搜索区间是[0，nums.length)为左闭右开，所以最后判断和返回时需要对left或者right减一，防止越界。这个"减一"也可以这么理解：'if (nums[mid]==target)left=mid+1;'当while循环结束的时候nums[left]的值一定不是target，但是nums[left-1]的值有可能是，所以返回‘nums[right-1]==target?right-1:-1’即可。
```java
    public int[] searchRange(int[] nums, int target) {
        int[] result={-1,-1};
        result[0]=searchLeft(nums,target);
        result[1]=searchRight(nums,target);
        return result;
    }
    //查找最左target
    public int searchLeft(int[] nums,int target){
        int left=0,right=nums.length;
        //这里是<而不是<=，因为搜索区间是[0，length)，终止条件是left==right
        while (left<right){
            int mid =(left+right)/2;
            //因为是寻找最左target，所以这里不能直接返回，而是收缩right去锁定左侧边界
            if (nums[mid]==target){
                right=mid;
            }else if (nums[mid]<target){
                left=mid+1;
            }else if (nums[mid]>target){
                //这里是=mid而不是=mid-1，因为搜索区间是左闭右开
                right=mid;
            }
        }
        //如果target比所有数都大，则返回-1
        if (left==nums.length)return -1;
        //终止条件是left==right，所以返回left或者right都可
        return nums[left]==target?left:-1;
    }
    //寻找最右target
    public int searchRight(int[] nums,int target){
        int left=0,right=nums.length;
        //这里是<而不是<=，因为搜索区间是[0，length)
        while (left<right){
            int mid=(left+right)/2;
            //因为是寻找最右target，所以不能直接返回，而是要增大left去锁定左侧边界
            if (nums[mid]==target){
                left=mid+1;
            }else if (nums[mid]>target){
                right=mid;
            }else if (nums[mid]<target){
                left=mid+1;
            }
        }
        if (right==0)return -1;
        //由于每次收紧左侧边界都是left=mid+1（因为搜索区间是左闭右开），所以无论是left还是right都需要-1
        return nums[right-1]==target?right-1:-1;
    }
```
时间复杂度：O(log n)

## 注意事项：
1. **二分法中比较麻烦容易出错的点就是搜索区间的确定，因为这会影响到循环条件和搜索区间端点(left和right)的移动。**
2. **思路一中：left=0，right=length-1所以搜索区间是[0，length-1]左闭右闭的，所以循环终止的条件是left>right即while(left<=right)，区间端点移动时因为mid不是需要的值所以排除，即left=mid+1，right=mid-1排除了mid并且新的搜索区间是[0，mid-1]或者[mid+1，lenght-1]依然是左闭右闭。**
3. **思路二中：left=0，right=length所以搜索区间是[0，length)左闭右开的，所以循环终止的条件是left==right所以while(left<right)即可，区间端点移动时因为mid不是需要的值所以排除，即left=mid+1，right=mid排除了mid并且新的搜索区间是[0，mid)或者[mid+1，lenght)依然是左闭右闭。**
