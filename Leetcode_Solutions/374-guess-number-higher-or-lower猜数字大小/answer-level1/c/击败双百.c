### 解题思路
二分法查找，测试点中会出现signed int的上限，所以不能直接做运算，必须进行强制转换

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
    long long mid=(1+(long long)n)/2, left=1, right=n, newmid;
    while(1){
        if(guess(mid)==1){
            if(mid==right-1) return right;
            newmid=(mid+right)/2;
            if(guess(newmid)==1) mid=newmid;
            else if(guess(newmid)==-1) right=newmid;
            else  return newmid;
        }
        else if(guess(mid)==-1){
            if(mid==left+1) return left;
            newmid=(mid+left)/2;
            if(guess(newmid)==1) left=newmid;
            else if(guess(newmid)==-1) mid=newmid;
            else  return newmid;
        }
        else  return mid;
        
    }
}
```