![image.png](https://pic.leetcode-cn.com/e78191f21dd687bdbcf38ac7339661a70b033451bd56e43f00b7ced6c8d015d1-image.png)

首先要在草稿纸上搞清楚什么是字典序的下一个排列，自己能够手写下一个排列。然后就不难想出我的这种思路了。当我也是经历了各种思维误区后才AC的。

### 解题思路
从后往前扫，如果右边的数比左边的大，那么就可以通过交换这两个数来使得整个排列更大。也就是说找到一个更大的数放到前面。但是这里要注意这个更大的数也不能最大，要是比前一个大的最小的数。现在直接看代码可能会清晰点。


### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        int i = nums.size()-1;
        int minIndex = i;
        int j = i;
        while(i>0 && nums[i]<=nums[i-1]){
            i--;
        }
        if(i==0){//扫到最后一组了，还没有找到“逆序”的数，说明这个数组就是从大到小排列的，也就是最大排列，
                // 这个时候直接将数组反转，就变成了从小到大排列，这样就是最小排列了。
            reverse(nums.begin(),nums.end());
        }else{
            minIndex = i;
                //找了了这个逆序的i，但是要注意i-1不一定和i换，而应该是和i往右的所有数中比i-1大的最小的数
            for(j=i; j<nums.size(); j++){
                if(nums[j]>nums[i-1] && nums[j]<=nums[minIndex]){
                    minIndex = j;
                }
            }
            swap(nums[minIndex],nums[i-1]);
// 这种sort的用法是我自己想出来的，网上的都是以begin()开头的，而我是以end结尾，然后往后倒推的。
            sort(nums.end()-(nums.size()-i),nums.end());
        } 
    }
};
```
(文字写得不严谨，但是代码是严谨的。有收获的话求个赞..)