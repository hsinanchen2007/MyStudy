### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/05678b59dd6925aedff9ecb08841393674d460c57b317a07667453ba8169e8a0-image.png)

![image.png](https://pic.leetcode-cn.com/98dc3fc6bfc42e53626e0fba870d08b9be9b751b40eedba653c88a4445c6a2fb-image.png)

一次循环转一圈
each_num表示本次循环要铺设的行或列需要多少个新数字
start表示本次循环从哪里开始
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int each_num = n-1;
        int m=1;
        vector<vector<int>> res(n,vector<int>(n,0));
        for(int start=0;each_num>=0;each_num-=2,start++){
            if(each_num==0) res[start][start]=m++;
            for(int i=start,j=start;j<start+each_num;j++) res[i][j] = m++;
            for(int j=start+each_num,i=start;i<start+each_num;i++) res[i][j] = m++;
            for(int i=start+each_num,j=start+each_num;j>start;j--) res[i][j] = m++;
            for(int j=start,i=start+each_num;i>start;i--) res[i][j] = m++; 
        }
        return res;
    }
};
```