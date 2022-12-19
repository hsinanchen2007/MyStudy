难点在于如何找到峰值

```
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0;
        int r = n-1;
        int peak = 0;
        
        while(l < r){
            int mid = (l + r)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid + 1;
                peak = mid + 1;
            }else{
                r = mid;
            }
        }
        
        l = 0;
        r = peak;
        while(l <= r){
            int mid = (l+r)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }else if(mountainArr.get(mid) < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        l = peak;
        r = n-1;
        while( l <= r){
            int mid = (l+r)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }else if(mountainArr.get(mid) < target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return -1;
    }
};
```
