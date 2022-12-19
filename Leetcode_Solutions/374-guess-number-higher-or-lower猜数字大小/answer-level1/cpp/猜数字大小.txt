题目就是要我们在1-n之间查找一个特定的数，是一道典型的二分查找题，可以根据提供的接口guess来判断我们要查找的数在左边还是右边。唯一需要注意的一点是int型溢出问题，如果我们定义中间数的时候赋值为：mid=(left+right)/2，那么就有可能因为(left+right)的结果超出int型范围导致运算出错。
![image.png](https://pic.leetcode-cn.com/833f6a0308e6d4b412ddc6bab39aa4e7441a3695ad9f6dde53e58a965b70ce19-image.png)

解决之道就是赋的值变为：mid=left+(right-left)/2。这两种赋值都是等价的，但无疑后面这种可以有效的防止运算过程出现溢出。
```
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left=1,right=n;
        while(left<=right)
        {
            int mid=left+(right-left)/2;//这样赋值可以防止运算过程出现溢出
            int result=guess(mid);
            if(result==0)
               return mid;
            else if(result==-1)
                right=mid-1;
            else
                left=mid+1;
        }
        return -1;
    }
};
```
