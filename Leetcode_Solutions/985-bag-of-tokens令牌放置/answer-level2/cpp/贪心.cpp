先对数组排序，使用双指针，left，right。
根据贪心策略，
令牌正面朝上，我们需要尽可能失去少的能量，从左往右，left++
令牌反面朝上，我们需要尽可能多得到能量，从右往左，right--

加上限定条件，不难得到结果。


```cpp
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.size() == 0){
            return 0;
        }
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int res = 0;
        int left=0,right=tokens.size()-1;
        while(left<=right){
            if(tokens[left]<=P){
                score++;
                P -= tokens[left];
                left++;
            }else{
                if(score<=0){
                    return res;
                }else{
                    P += tokens[right];
                    score--;
                    right--;
                }
            }
            res = max(res,score);
        }
        return res;
    }
};
```

![图片.png](https://pic.leetcode-cn.com/4bb742812e6e2a91828ca15c3500963961551522209d0a10cc413962d9c89f70-%E5%9B%BE%E7%89%87.png)
