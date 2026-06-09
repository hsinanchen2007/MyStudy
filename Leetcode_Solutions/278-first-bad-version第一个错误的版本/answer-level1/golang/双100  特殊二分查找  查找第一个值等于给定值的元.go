### 解题思路
此处撰写解题思路

### 代码

```golang
/** 
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad 
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
    low:=1
    high:=n

    for low <=high {
        mid:=low+(high-low)/2

        if isBadVersion(mid) {
          if ((mid==1)||isBadVersion(mid-1)==false) {
              return mid
          }else {
              high=mid -1
          }
            
        }else {
            low = mid + 1
        }
    }
    return -1
}
```