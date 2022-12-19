### 解题思路
此题关键在于hash的用法，在C++中可以用map代替。注意map的直接用[key]查找时，如果不存在就返回0。
因此如果map的second的元素如果可以0，将使map::[key]查找方法失效。恰好此题要求索引从1开始。因此在map中second存入的元素都大于0。不会影响查找。
最安全的方式是用map::find(key)查找。

根据题意，下标数对一定可以找到，且不相等。因此可以考虑用第二个元素匹配前面的所有元素，这个查找操作用hash。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> m;
        m[numbers[0]] = 1;
        for(int i=1;i<numbers.size();i++){
            if(m[target - numbers[i]])
                return {m[target - numbers[i]],i+1};
            else  
                m[numbers[i]] = i+1;
            
        }
        return {};
    }
};
```