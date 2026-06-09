 dp[i][j]代表了以（i，j)为岛屿的右下角结尾，从这里出发向左向上拉一个矩形，矩形内所形成的最大岛屿面积。
比如这个过程方便理解：
![image.png](https://pic.leetcode-cn.com/33da30de777d63aad4058c57e53b5b4581c2ebd8c22b8bbade236a57e388e934-image.png)


![image.png](https://pic.leetcode-cn.com/21f3af89db57a820b0284adaa403f36dcfb3d401a39bc76ca1ed76e25a211723-image.png)



![image.png](https://pic.leetcode-cn.com/33da30de777d63aad4058c57e53b5b4581c2ebd8c22b8bbade236a57e388e934-image.png)

所以得解 6为输出的正确答案

![image.png](https://pic.leetcode-cn.com/1e2ed5c2442539e7df823e7f816975db69f3c7e248de1a4f5df5a44e768221dd-image.png)
