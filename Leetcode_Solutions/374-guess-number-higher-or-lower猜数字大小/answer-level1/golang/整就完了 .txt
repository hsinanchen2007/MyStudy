### 解题思路
此处撰写解题思路
二分查找换个说法 脑袋转一会就好了

### 代码

```golang
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
    return binarySearch(n)
}

func binarySearch(n int) int {
    
    low := 1
    high := n
    var res int 
    for low <= high {
        mid := low + ((high - low) >> 1)

        fmt.Println(mid)
        if guess(mid) == -1 {
            high = mid - 1
        }else if guess(mid) == 1 {
            low = mid+1
        }else if guess(mid) == 0 {
            res = mid
            break
        }
    }
    return res
}
```