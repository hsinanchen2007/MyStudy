![image.png](https://pic.leetcode-cn.com/f2d275c6dcf2bd7269762291a107b28788b27ed96a84b42190cef2be6bad86c8-image.png)

### 解题思路
注释详细，有收获请点赞

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;//max记录当前能够到达的最大位置（下标）
        for(int i=0; i<nums.size(); i++){
            if(max<i){// 如果当前能够到达的最大下标还小于i，也就是连i都到不了，那么肯定到不了终点
                return false;
            }
            max = i+nums[i]>max?i+nums[i]:max;// 可能要更新当前能够到达的最大下标
            // 如果当前能够到达的最大小标都超过nums.size()-1了，那肯定能够到达终点
            if(max>=nums.size()-1) return true; 
        }
        return true; // 每一步都走完了，没问题，返回true
    }
};
```