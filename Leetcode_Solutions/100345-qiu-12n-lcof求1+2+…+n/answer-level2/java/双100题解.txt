![image.png](https://pic.leetcode-cn.com/091023c627b43009fd719f2c0a0f09e4335a7039bc2c4f9b9648a10330355d50-image.png)

```
class Solution {
    public int sumNums(int n) {
        return (n+(int)Math.pow(n,2))>>1;
    }
}
```
题目是一个等差数列，求和公式为n(a1+an)/2  >> (n*a1+n*an)/2
n*a1可以替换为n，因为a1=1
n*an可以替换为Math.pow(n,2)，因为an=n
/2可以替换为>>1