### 解题思路
也可以：
固定非0，最后清0数组
    for (int j = 0; j < nums.length; j++) {
        if (nums[j] != 0) {
            nums[fixed] = nums[j];
            fixed++;
        }
    }
    for (; fixed < nums.length; fixed++) {
        nums[fixed] = 0;
    }
}

作者：wang-zi-hao-zain
链接：https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-javajian-ji-ti-jie-bao-li-shuang-zhi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //这个算是什么方法呢，不知道。画了二叉分支来考虑，0或n
        //算是动规？或者是插入排序的思想
        int tmp;
        for(int i=1;i<nums.size();i++){ //从0 从1 都一样
            if(nums[i]==0){
                continue;
            }
            int j=i;
            while(j>0&&nums[j-1]==0){ //直到遇见前一个不是0了，退出循环
                j--;                //j的前一个是0，就往前走
            }
            if(nums[j]==0){  //退出循环时，j是第一个0
                tmp = nums[i];
                nums[i]=nums[j];
                nums[j]=tmp;
            }            
            else continue;
        }
    }
};
```