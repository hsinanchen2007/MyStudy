### 解题思路
二分法
注意：1、范围选取 2、范围收缩

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
    long low=1,high=n,mid=(low+high)/2;
    while(low<high)
    {
        mid=(low+high)/2;
        switch(guess(mid))
        {
            case -1:high=mid;break;
            case 1:low=mid+1;break;
            case 0:return mid;
        }
    }
    return low;
}
```