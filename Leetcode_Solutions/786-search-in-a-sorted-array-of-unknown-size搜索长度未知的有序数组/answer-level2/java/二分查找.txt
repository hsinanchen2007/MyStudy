```
class Solution {
    public int search(ArrayReader reader, int target) {
        //找数组长度
        //数组长度小于20000
        int left = 0,right = 20000;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(reader.get(mid) == 2147483647){
                right = mid;
            }else if(reader.get(mid) < 2147483647){
                left = mid + 1; 
            }
        }
        //数组长度为left
        int l = 0,r = left-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(reader.get(mid) == target) {
                return mid;
            }else if(reader.get(mid) < target){
                l = mid+ 1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
}
```
