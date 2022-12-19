### 解题思路
此处撰写解题思路
1、二分查找的编写
2、想明白就简单了
3、主要是查找的选择条件
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
    if n == 1 {
        return 1 
    }
    return binarySearch(n)
}

func binarySearch(n int) int {

    length := n

    low := 1
    high := length

    for low <= high {
        mid := low + ((high - low) >> 1)
        if !isBadVersion(mid) {
            low = mid+1
        }else if isBadVersion(mid) && isBadVersion(mid-1) {
            high = mid - 1
        } else if isBadVersion(mid) && !isBadVersion(mid-1){
            return mid
        }
    }
    return 0
}
```