通过观察规律，得出题为斐波那契数列
除前两个单独不符合规律之外，可用if判断直接输出

利用head和late不断更新斐波那契值
while执行一次，相当于在 有规律的部分（即从第三个数开始的）更新一次
从第三个数开始需更新一次，即3只需进行一次执行，所以n=n-2
返回更新得到的head


```
class Solution {
    public int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        else{
            int head = 2;
            int late = 1;
            n = n-2;
            while(n-- > 0){
                head = late + head;
                late = head - late;
            }
            return head;
        }
    }
}
```
![捕获.PNG](https://pic.leetcode-cn.com/672b967735b711f52392346089da8526a7727f0f20be378a01b53132f02eccbe-%E6%8D%95%E8%8E%B7.PNG)

