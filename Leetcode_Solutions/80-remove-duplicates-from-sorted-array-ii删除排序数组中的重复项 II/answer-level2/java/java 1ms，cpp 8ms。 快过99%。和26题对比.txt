```
class Solution {
    // Problem 80 java
    public int removeDuplicates(int[] nums) {
        if(nums.length <= 2){
            return nums.length;
        }
        int i = 2;
        for (int j = 2; j < nums.length; j++) {
            if(nums[i-2] != nums[j]){        // 关键
                nums[i++] = nums[j];
            }
        }
        return i;
    }
    // Problem 26 java
    public int removeDuplicates26(int[] nums) {
        if (nums.length <= 1){
            return nums.length;
        }
        int i = 1;
        for (int j = 1; j < nums.length; j++) {
            if (nums[i-1] != nums[j]) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
}
```
```
class Solution {
public:
    template<int K>
    int removeDuplicates(vector<int>& nums){
        if (nums.size() <= K){
            return nums.size();
        }
        int i = K;
        for (int j = K; j < nums.size(); j++) {
            if (nums[i-K] != nums[j]) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }

    // Problem 26 java
    int removeDuplicates26(vector<int>& nums) {
        return removeDuplicates<1>(nums);
    }
    // Problem 80 java
    int removeDuplicates80(vector<int>& nums) {
        return removeDuplicates<2>(nums);
    }
};
```

两个题目几乎一模一样，关键在于抽象出 i++的条件
26的条件比较好理解：已经处理完的数组的最后一个元素和当前元素不想等。
80条件的原始叙述：重复的元素允许有两个。已经处理玩的数组的倒数第二个元素和当前元素不相等。

ps:玩一下c++模版