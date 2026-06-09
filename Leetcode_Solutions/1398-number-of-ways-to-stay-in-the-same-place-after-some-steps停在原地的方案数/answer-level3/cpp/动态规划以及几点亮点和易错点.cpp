最开始直接用DFS做的，结果当然是超时。
后续改用DP。
1. 动手画出表格（谁横谁纵不重要），开始填，很快就能找到思路了
2. 注意int位数，这里改成unsigned int
3. 代码实现时注意表格行列数，比如这里的行数
4. 空间优化是最后才做的，主要从两方面优化
- 行数并不需要steps，两行就够了
- **列数并不需要arrLen，因为最终只取表格左下角那个元素，对其有影响的也就次对角线45度划上去的范围（这一步也优化了时间）**

结果：
![image.png](https://pic.leetcode-cn.com/fe4bf2425ca03a6d74472bd55702ef61b21662cdeb86a83c44caf43135f7ebc5-image.png)

```
//DP
class Solution {
public:
    unsigned int mod(unsigned int x){
        return x%((int)pow(10,9)+7);
    }
    
    int numWays(int steps, int arrLen) {
        int i,j;
        if(arrLen==1)
            return 1;
        steps++; //特别注意下表格的行列应为多大
        vector<vector<unsigned int>> m(2,vector<unsigned int>(((arrLen>steps+1)?arrLen:steps+1),0));  //防止空间过大，实际上只需两行,长度也不需要arrLen
        m[0][0]=1;
        for(i=1;i<steps;i++){
            m[i%2][0]=mod(m[(i-1)%2][0]+m[(i-1)%2][1]);
            for(j=1;j<=steps-i&&j<arrLen-1;j++){ 
                m[i%2][j]=mod(m[(i-1)%2][j-1]+m[(i-1)%2][j]+m[(i-1)%2][j+1]);
            }
            m[i%2][arrLen-1]=mod(m[(i-1)%2][arrLen-1]+m[(i-1)%2][arrLen-2]);
        }
        return m[(steps-1)%2][0];
    }
};
```
