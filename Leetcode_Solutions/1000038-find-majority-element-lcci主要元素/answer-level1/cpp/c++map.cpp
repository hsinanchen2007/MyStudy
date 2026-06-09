### 解题思路
map记录不同元素和每个元素出现的次数，再遍历map找到出现次数超过数组大小一半的元素并返回；

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        map<int,int>m;
        for(auto num:nums){
            if(m.find(num)!=m.end())(m.find(num)->second)++;
            else m.insert(pair<int,int>(num,1));
        }
        for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
            if(i->second>n)return i->first;
        }
        return -1;
    }
};
```