### 解题思路
此处撰写解题思路

题意要整清楚，第一做题时没有考虑 元素只能减小的条件和数据动态变化后的影响 所以做错误。代码贴到下边警示自己：

### 代码

```cpp
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> diff;

        for (int i = 0; i < nums.size() - 1; i++) {
            diff.push_back(nums[i + 1] - nums[i]);
            cout << diff[i] << endl;
        }

        vector<int> diffSum(4, 0);
        for (int i = 0; i < diff.size(); i++) {    //此种方法没有考虑 元素只能减小的条件。 数据动态变化后的影响
                                                   //用例[7,4,8,9,7,7,5] 不过
            if (i % 2 == 0) {
                if (diff[i] > 0) {
                    diffSum[0] += diff[i] + 1;
                } else {
                    diffSum[1] -= diff[i] - 1;
                }
            } else {
                if (diff[i] > 0) {
                    diffSum[2] += diff[i] + 1;
                } else {
                    diffSum[3] -= diff[i] - 1;
                }
            }
        }

        cout << diffSum[0] << diffSum[1] << diffSum[2] << diffSum[3] << endl;
        int maxOper = *max_element(diffSum.begin(), diffSum.end());
        if (maxOper == diffSum[0]) {
            return diffSum[2];
        } else if (maxOper == diffSum[1]) {
            return diffSum[3];
        } else if (maxOper == diffSum[2]) {
            return diffSum[0];
        } else if (maxOper == diffSum[3]) {
            return diffSum[1];
        }
        //minOper = min(min(evenPo, -evenNe), min(oddPo, -oddNe));
        
        return 0;
    }
};


### 代码

```cpp
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> vec1 = nums;
        vector<int> vec2 = nums;
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            //修改数组为 小大小
            if (i % 2 == 0) {  //奇数位
                if (vec1[i] - vec1[i + 1] >= 0) {
                    sum1 += vec1[i] - vec1[i + 1] + 1;
                    vec1[i] = vec1[i + 1] - 1;  //vec1[i] - (vec1[i] - vec1[i + 1] + 1)
                } else {
                }
            } else {
                if (vec1[i] - vec1[i + 1] > 0) {  //偶数位
                } else {
                    sum1 += vec1[i + 1] - vec1[i] + 1;
                    vec1[i + 1] = vec1[i] - 1;
                }
            }
            //修改数组为 大小大
            if (i % 2 == 0) {  //奇数位
                if (vec2[i] - vec2[i + 1] > 0) {
                } else {
                    sum2 += vec2[i + 1] - vec2[i] + 1;
                    vec2[i + 1] = vec2[i] - 1;
                }
            } else {
                if (vec2[i] - vec2[i + 1] >= 0) {  //偶数位
                    sum2 += vec2[i] - vec2[i + 1] + 1;
                    vec2[i] = vec2[i + 1] - 1;
                } else {
                }
            }
        }
        for (int i = 0; i < vec1.size(); i++) {
            cout << nums[i] << " " << vec1[i] << " " << vec2[i] << endl;
        }
        return min(sum1, sum2);
    }
};
```