### 解题思路
二分

### 代码

```c
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    //int count=0;
    int left=1;int right=n;
    int mid;
    while(left<right)
    {
        mid=(left+(right-left)/2);
        //count++;
        //printf("%d %d\n",left,right);
        //printf("%d\n\n",mid);
        //if(count==20) break;
        if(isBadVersion(mid)==true)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}
```