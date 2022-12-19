### 解题思路
类型转换to_string()

### 代码

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        // tag:类型转换
        // method:tostring
        vector<int>::iterator iter;
        int res=0;
        for(iter=nums.begin();iter!=nums.end();iter++){
            string tmp=to_string(*iter);
            if(tmp.size() %2 ==0){
                res++;
            }
        }
        return res;
    }
};
```