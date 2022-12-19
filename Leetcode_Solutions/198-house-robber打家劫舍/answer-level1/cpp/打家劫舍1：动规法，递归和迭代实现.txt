### 解题思路
递归也可以另外写一个函数，这个递归的时间复杂度等于求二叉树结点个数**，是2^n** ,可以用哈希表缓存一些已经计算过的参数，叫**备忘录算法**

迭代//得创建一个数组，来维护才行，而不是一个变量，
如果要节约空间复杂度，可以只用两个变量？？
### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
            // //肯定不是我想的，分成两组求和就行了，只是没想到2112 这种组合
            // int len = nums.size();
            // int sum2 = 0;
            // int sum1 = 0;
            // for(int i = 0;i<len;i++){
            //     if(i%2){
            //         sum1 += nums[i];
            //     }
            //     else{
            //         sum2 += nums[i];
            //     }
            // }
            // return sum1>sum2?sum1:sum2;


        // //动态规划迭代解法
        // int len = nums.size();
        // if(len ==0) return 0;
        // if(len ==1) return nums[0];
        // //if(len==2) return nums[1]>nums[0]?nums[1]:nums[0];
        // int a[len];
        // a[0] = nums[0];   //得创建一个数组，来维护才行，而不是一个变量
        // a[1] = nums[1]>nums[0]?nums[1]:nums[0]; //另外还得初始化前2个数
        // for(int i = 2;i<len ;i++){
        //     a[i] = max(nums[i]+a[i-2],a[i-1]);
        // }
        // return a[len-1];

        return call(nums.size()-1,nums); //递归也可以另外写一个函数，
    }
   int call(int k, vector<int>& nums){
        if(k==0)
            return nums[0];
        if(k == -1)
            return 0;
        //if(k==1) return max(nums[1],nums[0]);
        //return max(call(k-2,nums)+nums[k],call(k-1,nums));
        if(m.count(k))
            return m[k];//直接返回已经计算过的情况,减少迭代次数的
        m.insert(pair<int,int>(k,max(call(k-2,nums)+nums[k],call(k-1,nums))));                          //将已计算情况保存
        return m[k];//        
    }

private:
    unordered_map<int,int> m; //从使用来看，k是长度，第二个int 是计算得的最值
};
```