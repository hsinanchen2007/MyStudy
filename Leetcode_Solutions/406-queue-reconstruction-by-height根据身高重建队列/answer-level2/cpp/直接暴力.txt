### 解题思路
先将people数组按升序排列，从头开始遍历people数组,用p表示当前的人，p[0]表示自己身高、p[1]表示前面身高大于等于自己的人数。
- 用num表示res数组索引j之前的空位（留给大于等于比自己高的人）与身高等于自己的人的数目和。
- 只有当索引j的地方为空且num==p[1]，即前面身高大于等于自己的人为p[1]时，将p填在res的索引j处。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        vector<vector<int>>res(people.size());
        for(auto p : people){
            int j=0,num=0;
            while(res[j].size()>0||num<p[1]){//此处有人或者num还没达到要求
                if(res[j].size()==0||res[j][0]==p[0]) num++;//此处没人，或者有身高和自己相等的人
                j++;
            } 
            res[j]=p;
        }
        return res;
    }
};
```