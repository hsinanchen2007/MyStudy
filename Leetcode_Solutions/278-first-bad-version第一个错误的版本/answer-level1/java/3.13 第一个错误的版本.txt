### 解题思路
1.这道题给的背景有点复杂，但是仔细看一下，就是用二分法
2.二分将执行用时缩减，while(left<right)（这一步判断，如果left>right则证明这个里面没有想找的数）
3.然后用二分法来做

### 代码

```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left=1;
        int right=n;
        while(left<right){
          int mid=left+(right-left)/2;
          if(isBadVersion(mid)){
              right=mid;
          }
          else
          {
              left=mid+1;
          }
        }
      return right;

    }
}
```