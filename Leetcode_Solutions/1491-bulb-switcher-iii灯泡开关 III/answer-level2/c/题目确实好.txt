### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/e11af87de6c3001f29c820d563cffd3d3f15124432c2c86c77b3b92fc320437d-image.png)
当时我没做出来，有两个点：
1) sum需要使用long来存储，这个在所有题目要注意
2) 题目中一个很重要的点，就是某个时刻，所有的灯都是蓝色的话，那么和一定等于从1到n的等差数列之和！
### 代码

```c
int numTimesAllBlue(int* light, int lightSize){
    long sum = 0;
    int ans = 0;
    long cnt = 0;
    for (int i = 0; i < lightSize; i++) {
        sum += light[i];
        cnt++;
        if (sum == (cnt + 1) * cnt / 2) {
            ans += 1;
        }
    }

    return ans;
}
```