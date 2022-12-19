二分查找变形，先找左边界，找到左边界后，直接从左边界下标再进行一次二分查找，直至找到右边界
```
        if(a.length == 0) return 0;
        int low = 0;
        int high = a.length - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (a[mid] >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(a[low]!=k) return 0;
        int left = low;
        high = a.length-1;

        while(low<=high){
            int mid = low+((high-low)>>1);
            if(a[mid]<=k){
                low = mid+1;
            }else{
                high = mid-1;
            }

        }
        return low - left;
```
