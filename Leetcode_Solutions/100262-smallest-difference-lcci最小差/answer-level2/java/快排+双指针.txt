**第一次面试 面字节就是这道算法。当时思路有，紧张啊，就是写不出来。然后面试一结束，视频一关，就写出来了（****）

```
    public int smallestDifference(int[] a, int[] b) {
        quickSort(a,0,a.length-1);
        quickSort(b,0,b.length-1);
        int i=0;
        int j=0;
        long min = Integer.MAX_VALUE;
        int temp = 0;
        while(i < a.length && j < b.length){
            min = Math.min(min,Math.abs((long) (a[i] - b[j])));
            if(a[i]<=b[j]){
                i++;
            }else{
                j++;
            }
        }
        return (int)min;

    }
    public void quickSort(int[] nums,int left,int right){
        int l = left;
        int r = right;
        int temp = 0;
        int pivot = nums[(left+right)/2];
        while(l<r){
            while(nums[l]<pivot){
                l+=1;
            }
            while(nums[r]>pivot){
                r-=1;
            }
            if(l>=r){
                break;
            }
            temp = nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            if(nums[l]==pivot){
                r-=1;  
            }
            if(nums[r]==pivot){
                l+=1;
            }
        }
        if(l==r){
            l+=1;
            r-=1;
        }
        if(left<r){
             quickSort(nums,left,r);
        }
        if(right>l){
              quickSort(nums,l,right);
        }
    }
}


```

```

