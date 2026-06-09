![1.PNG](https://pic.leetcode-cn.com/51665794bc9a58bf23b777a8d83a57c7dc23360bada3fd4531d0c95b1ae9d17a-1.PNG)

利用二分法解决，思路蕴含在如下代码中：
```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=0,right=n;
        //long mid;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)==false&&isBadVersion(mid+1)==true)return mid+1;
            else if(isBadVersion(mid)==false&&isBadVersion(mid+1)==false)left=mid+1;
            else if(isBadVersion(mid)==true&&isBadVersion(mid+1)==true)right=mid;
        }
        return 0;
    }
};
```

