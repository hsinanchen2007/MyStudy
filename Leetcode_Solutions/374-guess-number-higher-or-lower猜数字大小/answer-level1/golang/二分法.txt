### 解题思路
此处撰写解题思路

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
	start,end:=0,n
	for start<=end{
		center:=(start+end)/2
		if guess(center)==0{
			return center
		}else if guess(center)==-1{
			end=center-1
		}else{
			start=center+1
		}
	}
	return 0
}
```