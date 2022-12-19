贪心算法的核心，就是找“完爆”。所谓“完爆”，便是“你所能做的我都能做，你不能做的我可以试试”。

显而易见的是，在这个问题中，[2, 4, 10, 5, 3, 4, 5]子序列[2, 4, 10]是被子序列[2, 4, 5]完爆的，而[2, 4, 5]也是被[2, 3, 4]完爆的。如果你和我一样在第五层，稍微思考一下应该也想得到[2, 4, 5]是被[2, 3, 5]完爆的，这时候第二层的同学可能会认为“诶，这个3还不一定会在最后的最长子序列里，你怎么就把它写进去了”呐，我就告诉你，因为最后只需要输出子序列的长度，所以把这个3扔进去，就算最后它没有起到作用，也是不亏的，对结果有可能产生直接影响的只有最后一个数，更新前面的数则为后面的数提供了变小的可能性，所以是完爆。

那么现在思路就很明显了，遍历数组，对每个数num， 查找 num > order[i-1] && num <=  order[i] 并替换order[i] 对特殊情况（首尾）处理一下，查找使用二分查找优化时间复杂度，这个带伙都会我就不说了。以上面的数组为例：

1. 直接写入 2:    [] -> [2]
2. 4 大于序列内所有值，push_back: [2] -> [2, 4]
3. 10 大于序列内所有值，push_back:: [2, 4] -> [2, 4, 10]
4. 5 大于 4 小于 10 替换 10: [2, 4, 10] - > [2, 4, 5]
5. 3 大于 2 小于 4 替换 4: [2, 4, 5] -> [2, 3, 5]
6. 4 大于 3 小于 5 替换 5: [2, 3, 5] -> [2, 3, 4]
7. 5 大于序列内所有值，push_back: [2, 3, 4] -> [2, 3, 4, 5]
8. 结束 返回序列长度 4；

代码：
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> orders;
        orders.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i ++){
            locandreplace(orders, nums[i]);
        }
        return orders.size();
    }
    void locandreplace(vector<int>& orders, int num){
        if(num > orders.back()){
            orders.push_back(num);
            return;
        }
        int low = 0;
        int high = orders.size() - 1;
        int cur = (low + high) / 2;
        while(!(num <= orders[cur] && (cur == 0 || num > orders[cur-1]))){
            if(num > orders[cur]){
                low = cur + 1;
                cur = (low + high) / 2;
            }
            if(num < orders[cur-1]){
                high = cur - 1;
                cur = (low + high) / 2;
            }
        }
        orders[cur] = num;
        return;
    }
};
```

