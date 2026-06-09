做了有十多个题了，第一次不看题解做出来了，有够笨的

根据上一个重复数取单，给出如下程序

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(); // 定义数组长度

        if(len==0){     // 空集返回0
            return 0;
        }

        for(int i = 0; i<len; i++){ // 遍历
            if(nums[i]==val){
                for(int j = i; j<len-1; j++){ // 如果有相同的值，就将它后面的所有元素前移
                    nums[j] = nums[j+1];
                }
                i--;    // 由于前移，新值到了当前位置，下一次仍要在此位置判断，所以先--，for循环中++，保持位置不变
                len--;  // 删除值了长度也要减小
            }
        }

        return len;
    }
};



