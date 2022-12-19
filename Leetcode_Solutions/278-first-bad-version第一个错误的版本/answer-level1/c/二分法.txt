### 解题思路
注意细节，特别是循环结束条件

### 代码

```c
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int head,tail,mid;
    head=1;tail=n;//搜索区间[1,N]闭区间
    while(head<=tail){
        mid=head+(tail-head)/2;
        if(isBadVersion(mid)==false){
            head=mid+1;
        }
        else if(isBadVersion(mid)==true){
            tail=mid-1;
        }
    }
    return head;//循环结束head=tail+1
}
```