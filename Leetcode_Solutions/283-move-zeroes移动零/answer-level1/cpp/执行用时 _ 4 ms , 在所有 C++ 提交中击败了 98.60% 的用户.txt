### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了98.60%的用户，就是耗得内存比较大10.4MB.
思路：利用两个变量i和a
nums[i]负责遍历数组，nums[a]负责储存非0值

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,t,a=0;
        
        for (i = 0; i < nums.size(); i++)
        {
            
            if (nums[i] != 0) {
                if(a!=i)/*若a等于i，则nums[i]不用移动，不移动的话不用让其值为0*/
                {         
                    nums[a]=nums[i];
                    nums[i]=0;//一旦移动，被移动位置的值为0
                 }
                a++;
            }
        }
      
      
    }
};
```