二分查找找到target所在位置，又因为是排序数组，只需看找到的位置附近的值是否为target即可。
```
int search(int* nums, int numsSize, int target){
    int fre=0;                      
    int low=0,high=numsSize-1;      
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==target){              //找到target
            ++fre;
            int i=mid-1;                //看mid左边是否有值为target的元素
            while(i>=0&&nums[i]==target){      i要>=0
                fre++;
                i--;
            }
            int j=mid+1;                //看mid右边是否有值为target的元素
            while(j<=numsSize-1&&nums[j]==target){      下标j要<=numsSize-1
                fre++;
                j++;
            }
            return fre;

        }else if(nums[mid]<target)
            low=mid+1;
        else   
            high=mid-1;
    }
    return 0;
}
```
