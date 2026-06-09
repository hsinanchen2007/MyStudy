### 解题思路
此处撰写解题思路

### 代码

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //binary search
        unsigned int begin = 1;
        unsigned int end = n;
        while(begin<end){
            unsigned int mid = (begin+end)/2;
            if(!isBadVersion(mid)){
                if(isBadVersion(mid+1)){
                    return mid+1;
                }else{
                    begin = mid +1;
                }
            }else{
                if(!isBadVersion(mid-1)){
                    return mid;
                }else{
                    end = mid -1;
                }
            }   
        }
        return 1;
    }
};
```