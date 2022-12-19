### 解题思路
1.使用二分查找，对传统二分查找进行一些修改。
2.因为根据题目解析，若发现不是错误版本，则其前期版本都不是错误版本，若发现是错误版本则后面的所有版本都是错误的。
3.因此若发现版本是错误，则将mid指针赋值于right指针，若发现版本是正确的，则将mid指针加1赋值于left指针。

### 代码

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid)){
                right = mid;
            }
            
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
```