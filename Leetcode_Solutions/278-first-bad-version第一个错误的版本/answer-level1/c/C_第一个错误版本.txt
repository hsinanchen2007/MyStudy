### 解题思路
mid 不能用 （low+high）/2 因为测试用例会很大，产生溢出。

### 代码

```c
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low=1,high=n;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(isBadVersion(mid))
            if(isBadVersion(mid-1))
                high=mid-1;
            else 
                return mid;
        else
            low=mid+1;
    }
    return 1;
}

```