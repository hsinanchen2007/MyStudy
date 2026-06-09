# 思路要点
1. 用两个指针来进行维护，[0, a]的部分是0， [b, size]的部分是2
2. 用k来表示当前指向元素
3. nums[k]与nums[b]交换后，nums[k]的值不一定，这种情况下k值不能增加，需要进一步判断nums[k]的值
4. nums[k]与nums[a]交换后，由于nums[a]的值已经遍历过(等于2已经和nums[b]做了交换)，因此nums[k]的值可能是0或1，当nums[k]==1时，也符合1处于(a, b)之间的情况，不需要进行进一步处理，因此只需将k=k+1就可以。
```cpp
class Solution {
private: 
    void swap(vector<int> & nums, int i , int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        int a = -1, b = nums.size(), k = 0;
        while(k < b){
            if(nums[k] < 1){
                ++a;
                swap(nums, a, k);
                ++k;
            }else if(nums[k] > 1){
                --b; 
                swap(nums, k, b);
            }else 
                ++k;
        }
    }
};
```