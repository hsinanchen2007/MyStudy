### 解题思路
c++暴力法，运用顺序容器和迭代器
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>result;
       vector<int>::iterator i;
       vector<int>::iterator j;
       int m=0;
       for(i=nums.begin();i!=nums.end();i++){
           int n=m+1;
           for(j=i+1;j!=nums.end();j++){
               if(*i+*j==target){
                   result.push_back(m);
                   result.push_back(n);
               }
               n++;
           }
           m++;

       }
       return result;
    }
};
```