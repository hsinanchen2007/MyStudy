过不了的问题主要出在测试用的83521和2401这两个数上，分别是17和7的四次方。

写法没啥特别的，遍历到根号，计数，但是比赛全程都卡在最后这个巨长的用例上，始终找不到为啥。
这是比赛途中采用的代码：
```
#include <math.h>

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            int cnt = 0;
            int sum = 0;
            
            for(int j = 2; j < sqrt(nums[i]); ++j){
                if(nums[i] % j == 0){
                    cnt++;
                    sum += j;
                    sum += nums[i] / j;
                    
                }
                if(cnt > 1) break;
            }
            if(cnt == 1){
                res = res + sum + nums[i] + 1;
            } 
        }
        
        return res;
    }
};
```
这里我以为`j < sqrt(nums[i])`而不用等于就可以避免平方根的问题，但是显然忽略了更高阶的四次方情况。

排错方式比较智障，人工二分法测试，找到了83521和2401这两个数，发现其四次方特性。
参考评论区各位前辈代码，把平方判断单独拿出来写：
```
#include <math.h>

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            int cnt = 0;
            int sum = 0;
            int sq = sqrt(nums[i]);

            for(int j = 2; j <= sq; ++j){
                if(nums[i] % j == 0){
                    cnt++;
                    sum += j;
                    sum += nums[i] / j;
                    
                }
                if(cnt > 1) break;
            }
            if(cnt == 1 && sq * sq != nums[i]){
                res = res + sum + nums[i] + 1;
            } 
        }
        
        return res;
    }
};
```
通过~