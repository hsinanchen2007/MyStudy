## 题解1
按照题意遍历原数组模拟合并连续的，不连续的成为单元素区间。
## 代码1
```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int len = nums.size(), prev, cnt = 0;//prev记录上一个元素 cnt统计连续元素个数
        string tmp;//记录区间
        for(int i = 0; i < len; ++i){
            if(i == 0 || nums[i] == prev + 1){
                prev = nums[i];
                ++cnt;
                if(cnt == 1)
                    tmp.append(to_string(nums[i]));
            }
            else{
                if(cnt > 1){
                    tmp.append("->");//区间元素超过一个，需添加"->"
                    tmp.append(to_string(prev));
                }
                res.push_back(tmp);
                tmp.assign(to_string(nums[i]));
                prev = nums[i];
                cnt = 1;
            }
        }
        //对最后一个区间单独处理
        if(cnt > 1){
            tmp.append("->");
            tmp.append(to_string(prev));
        }
        if(cnt > 0)//当数组长度为0 不添加“”进res
            res.push_back(tmp);
        return res;
    }
};
```

## 执行结果1
![在这里插入图片描述](https://pic.leetcode-cn.com/2dd7e4370dedd562f4083c2e37bc3f65c8e0fb204fec5be23ae003e9537fcd76.png)