### 解题思路
这种解法只能针对vecotr，双指针可能更好

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        for(vector<int>::iterator iter=nums.begin();iter!=nums.end();){        //从vector中删除指定的某一个元素 
            if(*iter==0){
                nums.erase(iter);zero++;
            }
            else iter++;
        }
        for(int i = 0; i < zero; i++) nums.push_back(0);
        return;
    }
};
```