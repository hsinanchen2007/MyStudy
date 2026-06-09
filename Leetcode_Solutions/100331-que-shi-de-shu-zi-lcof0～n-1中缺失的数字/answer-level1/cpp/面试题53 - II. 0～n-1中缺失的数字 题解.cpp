哎好菜啊，二分都不会了写了出了三个bug，还好检查的快。 Leecode的无调试debug还是相当锻炼人的。

简单思路：hash一下每个数据，找出空白值即可。

二分思路：依据前半部分有`nums[i] == i`的性质，和后半部分`nums[i] ！= i`的不同可以二分数据，从而找出错位的第一个数据。但是错位的数据不一定是缺少的数据，如果`i==len(nums)`就可能有缺失数据$n-1$的可能性。

```
cpp
class Solution {
public:
//     int missingNumber(vector<int>& nums) {
//         int len = nums.size();
//         int *hs = new int[len + 1];
//         //未初始化，或者说函数中new的数组初始状态非零
//         memset(hs,0, sizeof(int) * (len + 1) );
//         for(int i = 0;i < len ; ++i) hs[nums[i]] = 1;
//         for(int i = 0;i < len + 1; ++i)
//             if( hs[i] == 0) 
//                 return i; 
//         return 0;
//     }
// };

    int missingNumber(vector<int>& nums) {
        int right = nums.size() - 1, left = 0, mid = right;
        //bug1 边界情况
        if(nums[right] == right) return right + 1;
        while(left < right){
            mid = (left + right) / 2;
         //bug2 二分错误
            if( nums[mid] == mid )
                left = mid + 1;
            else if( nums[mid] != mid)
                right = mid;
        }
        //bug3 mid值没被更新, 而 left 和 right 都可以
        return left;
  
    }
};
​```
```





