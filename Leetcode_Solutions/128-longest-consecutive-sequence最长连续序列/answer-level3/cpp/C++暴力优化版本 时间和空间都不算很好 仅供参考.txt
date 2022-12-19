```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        //边界条件
        if(len<=1)
            return len;
        //依次遍历 遍历到第i个元素时 在vector中看 nums[i]+1是否存在 也就是把当前值看做是最小的
        //情况A：如果nums[i]+1存在 然后再向两端扩展1位 做类似的判断
        //情况B：如果nums[i]+1不存在 则继续向后遍历
        // 这种朴素的思路正确性没有问题 但是造成了大量的重复 因为当前数nums[i]如果作为序列的非最小值时会出现很多重复
        // 因此先判断nums[i]-1是否存在 如果存在跳过 这样不会漏掉任何数同时避免了重复

        //将vector的数据转存到map 进行O(1)查询加速 这样做是值得的
        map<int,int> mymap;
        for(int k=0;k<len;k++){
            mymap.insert(make_pair(nums[k],1));
        }
        int maxlen = 1;
        for(int i=0;i<len;i++){
            int curlow = nums[i];
            int step = 1;
            int curmaxlen = 1;
            //当前数值是中间值 并非最小值 跳过
            if(mymap.find(nums[i]-1)!=mymap.end())
                continue;
            //以nums[i]作为最小值向后扩散
            //使用find是O(n)的遍历 会超时 因此改造为map
            while(mymap.find(nums[i]+step)!=mymap.end()){
                curmaxlen++;
                step++;
            }
            maxlen = maxlen>curmaxlen?maxlen:curmaxlen;
        }
        return maxlen;
    }
};
```
