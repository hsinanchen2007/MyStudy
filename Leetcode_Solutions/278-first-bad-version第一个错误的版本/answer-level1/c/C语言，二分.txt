### 解题思路
此处撰写解题思路

### 代码

```c
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    long low=1;
    long high=n;
    while(low<high){
        long mid=(low+high)/2;
        if(!isBadVersion(mid)){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
}
```