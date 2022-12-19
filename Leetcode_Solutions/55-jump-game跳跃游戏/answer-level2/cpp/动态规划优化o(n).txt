我们先看朴素动态规划算法：
int i, j;
for(f[0] = i = 1;i < nums.size();i++)
    for(int j = 0;j < i;j++)if(i <= nums[j] + j)
        f[i] |= f[j]
这显然是o(n^2)的算法。但我们的状态转移方程事实上只要存在一个f[j](i <= nums[j] + j)=1，f[i]就为1.又由于i单调递增且每次只增加1，那么只需用一个变量h2存储到i - 1的时候总共有多少个f[j] = 1(j < i)，再增加一个桶h1[k]存储有多少个nums[j] + j == k即可o(1)转移。代码如下：
class Solution {
public:
    int h1[100005];
    int min(int a, int b){return a < b ? a : b;}
    bool canJump(vector<int>& nums){
        int i, j, h2;
        for(i = 0;i < nums.size();i++)nums[i] = min(nums[i], nums.size());//防止h1数组越界
        for(i = 1, h2 = h1[nums[0]] = 1;i < nums.size();i++){
            h2 -= h1[i - 1];
            h1[i - 1] = 0;
            if(h2){
                h1[nums[i] + i]++;
                h2++;
            }
        }
        return h2;
    }
};