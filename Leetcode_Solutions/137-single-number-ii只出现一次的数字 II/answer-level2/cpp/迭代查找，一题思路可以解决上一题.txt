### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(vector<int>::iterator it = nums.begin();it != nums.end();it++){
            vector<int>::iterator its = it+1;
            vector<int>::iterator ret = find(its,nums.end(),*it);
            if(ret == nums.end()) //没有找到
                return *it;
            else  //找到
                {
                    nums.erase(ret);   //删除找到的数，删除后，后面的数自动前移
                    ret = find(ret,nums.end(),*it);  //继续查找
                    nums.erase(ret);  //查找马上删除
                }   
        }
        return nums.back();
    }
};
```