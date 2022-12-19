### 解题思路
![12.JPG](https://pic.leetcode-cn.com/53fc0339ac0a1aab96dffe22f9f17d41a80d772ffadb062c05f15efad4b25165-12.JPG)


由于题目给出nums数组最大值不超过100，因此可以设置一个标记数组来记录输入数组里面每个数的个数，
然后利用一个类似动态规划的方式将小于某个数的个数记录下来，复杂度和内存消耗勉强可以接受。

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //利用题目给出的条件
        vector<int> label(101,0);
        for(int i = 0; i < nums.size(); i++){
            ++ label[nums[i]];
        }
        vector<int> label_2(101,0);
        for(int i = 1; i < 101; i++){
            label_2[i] = label[i-1] + label_2[i-1];
        }

        for(int i = 0; i < nums.size(); i++){
            nums[i] = label_2[nums[i]];
        }
        return nums;


        //暴力循环法
        // vector<int> num(nums.size(),0);
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = 0 ; j < nums.size(); j++){
        //         if(nums[i] > nums[j]){
        //             ++ num[i];
        //         }
        //     }
        // }
        // return num;
    }
};
```