### 解题思路
不管哪一行，都可以把数据归结为 0110 1001 这两种顾虑，举例好理解：
N=7时，数据为：0110100110010110 1001011001101001 1001011001101001 0110100110010110
若把 0110100110010110 看作 0，1001011001101001 看作 1，其实也就是 0110；
单独把：
0110100110010110 再分组：0110 1001 1001 0110，其实还是0110
1001011001101001 再分组：1001 0110 0110 1001，其实就是1001
可以看出：我是把 0110 看作 0，1001 看作 1
因此我就是把整个数据，一直循环分成 4 组，直到落到最小单元 0110 或者 1001
![image.png](https://pic.leetcode-cn.com/fa2443a79a5053bc7b0dee251ff96fdaa5fd039a90d4f8684b0f5de3b1d92b5a-image.png)



### 代码

```java
class Solution {
    private static final int[] a = {0,1,1,0};
    private static final int[] b = {1,0,0,1};
    public int kthGrammar(int N, int K) {
        //和 N 关系不大
        if(K <= 4)  return a[K-1];

        int nLen = (int) Math.pow(2,N-1);
        boolean flag = true;//true 代表是a数组规律，false 代表 b数组规律
        for (int step = nLen/4; step >= 1; step = step/4)
        {
            if(flag)
            {

                if(step > 4?a[(K-1)/step] == 1:a[(K-1)/4] == 1)
                {
                    flag = false;
                }
                if(step > 4)                K = K % step == 0? step:K % step;
                else                        K = K % 4== 0? 4:K % 4;
            }
            else
            {
                if(step > 4?b[(K-1)/step] == 0:b[(K-1)/4] == 0)
                {
                    flag = true;
                }
                if(step > 4)                K = K % step == 0? step:K % step;
                else                        K = K % 4== 0? 4:K % 4;
            }
        }
        return flag?a[K-1]:b[K-1];
    }
}
```