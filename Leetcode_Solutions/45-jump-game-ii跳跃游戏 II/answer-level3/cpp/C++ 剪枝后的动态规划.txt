### 解题思路
新建一个辅助数组，用来存放到第x个位置最少的跳数
从第i个位置开始，若第i个位置的当前跳数+1小于第i+1~i+nums[i]的跳数，则更新第i+1~i+nums[i]的跳数，直到判断当前位置已能跳过结尾，则直接输出当前跳数+1
笔者第一次未剪枝提交后发现最后一个sample刚好是一个递减数列，
![微信图片_20191228155728.png](https://pic.leetcode-cn.com/37b16fe9ec9c32688120f441018648a2f876d2ac4a3c1dcd78b2ee71bc9bbf90-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191228155728.png)
也就是说每一次进一位都要重新做nums[i]次，时间复杂度瞬间提升至n^2，因此在此基础上设置一个辅助变量farthest，记录前一次计算所能达到的最远距离，若当前的nums[i]+i没超过farthest，则无需计算，因为前一次已经将距离为farthest以内的所有p[]都更新过了，必然不会比前面用的跳数少
![1577520534(1).png](https://pic.leetcode-cn.com/15c98321743df9ef28eb16c05a37eaabea5624360ed32570af4210d459b9bfe0-1577520534\(1\).png)

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0;
        if (size(nums)<=1) return 0;
        int *p= new int[size(nums)];
        for (int i=0;i<size(nums);i++) p[i]=INT_MAX;
        p[0]=0;
        for (int i=0;i<size(nums);i++){
            if ((i+nums[i]+1)>=size(nums)) return p[i]+1;
            else if ((i+nums[i])>farthest) {
                for (int j=farthest-i;j<=nums[i];j++){
                    if (p[i]+1<p[i+j]) p[i+j]=p[i]+1;
                }
                farthest=i+nums[i];
            }
        }
    return -1;
    }
};
```