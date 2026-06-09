1. 主要是要查到该数组的终点。
2. 然后利用二分查找查找到关键的target。
```
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int binarySearch(const ArrayReader& reader,int l,int r,int target){
        while(l <= r){
            int mid = (l+r)>>1;
            int key = reader.get(mid);
            if(key == target){
                return mid;
            }else if(key > target){
                r = mid - 1;
            }else if(key < target){
                l = mid + 1;
            }
        }
        
        return -1;
    }
    
    int search(const ArrayReader& reader, int target) {
        int l = 0;
        int r = 10000;
        
        while(reader.get(r) != INT_MAX){
            if(reader.get(r) >= target){
                break;
            }else{
                l = r;
                r += 10000;
            }
        }
                
        if(reader.get(r) == INT_MAX){
            int l1 = l;
            while(l1 < r){
                int mid = (l1+r)>>1;
                if(reader.get(mid) == INT_MAX){
                    r = mid;
                }else{
                    l1 = mid + 1; 
                }
            }
            r = r-1;
        }
                
        return binarySearch(reader,l,r,target);
    }
};
```