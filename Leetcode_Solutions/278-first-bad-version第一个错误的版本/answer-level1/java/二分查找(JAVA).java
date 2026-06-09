### 解题思路
都在注释里了.

### 代码

```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 1;//初始化左界限为1
        int right = n;//初始化右界限为n
        while(left < right)//因为是左闭右闭区间,所以存在[left,left] 或者[right,right]的元素,而这道题就是当这个时候就输出最后的结果,所以=不能要
        {
            int mid = left + (right - left)/2;//计算mid
            if(isBadVersion(mid)==false)//如果是正确的版本,说明左界限需要移动,并且应该移动到mid的右边一个(因为该元素已经被确定了不可能是错版本)
            {
                left = mid + 1;
                
            }else{//如果是错误的版本 右界限需要移动,并且应该 = mid  因为该版本被检测出是错误的,只不过不能确定是最后一个元素罢了. 最后也应该返回right,因为它永远都是错版本.
                right = mid;
            }
        }
        return right;
    }
}
```