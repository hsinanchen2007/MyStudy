算法思路：可以发现规律，对于任意一个旋转排序数组nums，设数组的第一个元素位置为left，最后一个元素位置为right，则必有：
[left,mid]区间或者[mid,right]区间至少有一个区间是完全有序的，
例如：对于旋转数组 3 4 5 6 7 1 2，left=0，right=6，mid(left+right)/2=3,
[left,mid]=>[0,3]区间所有元素为3 4 5 6
[mid,right]=>[3,6]区间所有元素为6 7 1 2
显然左半边区间是有序的,同时，判断是否有序只需要判断左半边区间的左端点nums[0]<nums[3]是否成立即可。利用这个特性，我们可以实现算法如下：

首先令 i=0,j=numSize-1
当i<=j时执行以下步骤

    计算出mid=(i+j)/2,判断如果nums[mid]==target，则直接返回mid
    如果左半边区间[i,mid)区间有序（注意区间的一定时左边闭区间，右边因为mid已经判断了，可以是开区间）要分两种情况：①如果target的值介于该区间内，则继续进入该区间搜索，j=mid-1②如果target的值不介于该区间，则说明target要么不存在，要么再另外一个区间，而存不存在暂时不能判断，所以直接进入另外一个区间继续搜索，i=mid+1
    如果左半边区间无序，那右半边区间一定是有序的，判断步骤和第二步相仿。

如果循环执行完都没找到，那么显然数组中没有target，直接返回-1
算法实现

int search(int* nums, int numsSize, int target){
    int i=0,j=numsSize-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(nums[mid]==target){
                return mid;
        }
        //当(mid,j]区间元素有序时
        if(nums[mid]<nums[j]){
            //如果target在(mid,j]区间时
            if(nums[mid]<target&&nums[j]>=target){
                i=mid+1;
            }
             //如果target在[i,mid)区间时
            else{
                j=mid-1;
            }
        }
        //当[i,mid)区间元素有序时
        else{
            if(nums[mid]>target&&nums[i]<=target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }//nums[i]<nums[mid]
    }
    return -1;
}