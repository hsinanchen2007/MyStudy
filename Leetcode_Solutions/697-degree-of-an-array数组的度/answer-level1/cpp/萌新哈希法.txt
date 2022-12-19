**此处为正确代码**
```
 int findShortestSubArray(vector<int>& nums) {
        map<int,int> cnt;      //存储数字出现的次数
        int max = 0;
        int sIndex = 0;         //记录度数字初始位置
        map<int,bool> error;    //防止度数字重复计算
        for(int i = 0;i<nums.size();i++)
        {
            cnt[nums[i]]++;
            error[nums[i]]=true;      //初始化忽略数map
            if(cnt[nums[i]]>max)
            {
                max = cnt[nums[i]];     //记录度数
            }
        }
        int ans = 1e9;
        for(int i=0;i<nums.size();i++)
        {
            if(max==cnt[nums[i]]&&error[nums[i]])    //出现次数最大且是第一次出现
            {
                error[nums[i]] = false;
                int t = max;
                int temp =0;
                sIndex = i;
                for(int j = sIndex;t>0;j++)
                {
                    temp++;
                    if(nums[j]==nums[i]) t--;         //计算相同度子列长度
                }
                ans= min(ans,temp);                     //返回最小值
            }
        }
        return ans;
    }
```

没看题解，基本思路是通过哈希表统计数组度，然后找出度元素，最后统计长度。
代码有些杂乱，第一版无法通过但思路比较清晰的代码附在后面：
```
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> cnt;
        int max = 0;
        int finIndex = 0;
        int coolnum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            cnt[nums[i]]++;
            if(cnt[nums[i]]>max)
            {
                max = cnt[nums[i]];
                coolnum = nums[i];
                finIndex = i;     //记录下度最大的元素最后出现的位置
            }
        }
        int ans = 0;
        for(int j =finIndex;max>0;j--)
        {
            ans++;
            if(nums[j]==coolnum) max--;
        }
        return ans;
    }
};
```
如果改进意见，望在评论区提出。
