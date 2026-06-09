### 解题思路
![image.png](https://pic.leetcode-cn.com/ba3f115d8f349faf48fb31dcbf99bd63f866fecbd5194f4209c0b97ffb467818-image.png)

### 代码

```c
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
    if(guess(n) == 0) {
        return n;
    }
    long low = 1;
    long high = n;
    long mid;
	while(1) {
        mid = (low + high) / 2;
        int ret;
        ret = guess(mid);
        if(ret == 0) {
            return mid;
        } else if (ret == 1) {
            low = mid;
        } else {
            high = mid;
        }  
    }
}
```