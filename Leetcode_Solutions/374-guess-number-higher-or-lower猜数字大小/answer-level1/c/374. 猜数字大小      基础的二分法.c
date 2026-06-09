### 解题思路
函数的注释应该时说反了

我们正在玩一个猜数字游戏。 游戏规则如下：
我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
每次你猜错了，我会告诉你这个数字是大了还是小了。
你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：

-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！
示例 :

输入: n = 10, pick = 6
输出: 6



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
	int min=1, max=n, mid, ret;
    while(min <= max){
        mid = min + (max - min)/2;
        ret = guess(mid);
        //printf("n=%d mid=%d ret=%d\n", n, mid, ret);
        if(ret == 0)
            return mid;
        else if(ret == 1)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return -1;
}
```