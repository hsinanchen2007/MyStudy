### 解题思路
1、首先把数组从小到大排序，目的是可以通过双指针进行比较。
2、从头开始定位一个值，然后从剩下的数组(排好序)中找两个数之和等于-定位值。
3、找到在把此时三个位置的值暂存起来，然后两个指针继续缩小，同时需要跳过相同数据，否则有重复。
4、如果没有找到，则继续两边分头++ 或者--，继续比较。
5、一轮完成后，继续从第二个开始进行第二轮，注意在最外轮，比较时候也需要去重，跳过。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());/*将数据从小到大排序*/
        for(int i = 0 ; i < nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]){/*外层循环跳过重复,这里很重要*/
                continue;
            }
            int j = i +1; // left pointer
            int k = nums.size()-1; //right pointer
            while(j < k){ /*遍历排序好的后面的数组*/
                if(nums[j]+nums[k]+nums[i]==0){/*说明找到*/
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    result.push_back(v);
                    j++;/*下一位*/
                    k--;/*下一位*/
                    /*但是还需要判断增加后是否是和前一个数据一样*/
                    while( nums[j] == nums[j-1] && j < k){/*这里内部遍历时候一定要防止j不能大于k*/
                        j++;
                    }
                    while(nums[k] == nums[k+1] && j < k ){
                        k--;
                    }
                }
                if(nums[j]+nums[k] + nums[i]> 0){
                    k--;/*表示数据大了，向左移最后指针*/
                }
                if(nums[j]+nums[k] +nums[i] < 0){
                    j++;/*表示数据不够大，向右移动左边指针*/
                }
            }  
        }
        return  result;
    }
};
```