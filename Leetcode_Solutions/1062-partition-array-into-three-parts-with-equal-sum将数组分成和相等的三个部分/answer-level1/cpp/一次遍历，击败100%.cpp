**思路**：
①先求和判断其和sum是否能被3整除，不能的话直接return false。

②定义cnt=0，curSum=0，target=sum/3，遍历向量中元素，每次curSum加上当前元素，再判断是等于target。
若等于的话说明找到了第一个i的位置，令curSum=0，cnt++。

③return cnt>=3。

```
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=accumulate(A.begin(),A.end(),0);
        if(sum%3) return false;
        int curSum=0,target=sum/3,cnt=0;
        for(int i=0;i<A.size();i++){
            curSum+=A[i];
            if(curSum==target) {
                cnt++;
                curSum=0;
            }
        }
        return cnt>=3;
    }
};
```

![image.png](https://pic.leetcode-cn.com/53ed96cd464867763297d850274f78ab8c6cd8d7ab1cab825b44814d88dd92f3-image.png)

