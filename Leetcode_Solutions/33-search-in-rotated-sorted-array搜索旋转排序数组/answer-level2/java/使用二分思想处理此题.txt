此题主要强制使用log(n)的时间复杂度，能够达到的就是二分法，实现类似的是归并排序中的二分法。
也就是将数组不断的进行二分，然后在各个区域中找，如果区域中没有则返回-1，然后对返回的索引进行最大值比较，如果都为-1
则就没有，如果某个区域有，则就返回区域中的最大值（其他的都是-1，因为没有重复的）
代码实现如下:
```
public int search(int[] nums,int target){
        if (nums==null)return -1;
        return split(nums,0,nums.length-1,target);
    }

    private int split(int[] nums,int l,int r,int target){
        if(l==r){
            if (nums[l]==target)
                return l;
            else
                return -1;
        }
        int mid=l+(r-l)/2;
        return Math.max(split(nums,l,mid,target),split(nums,mid+1,r,target));
    }
```