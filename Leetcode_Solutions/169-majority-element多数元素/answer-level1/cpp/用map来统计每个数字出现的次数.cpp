### 解题思路
定义map（元素值，元素出现次数）
遍历数组，统计每个元素出现的次数
然后遍历map,找到出现次数最多的元素

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(vector<int>::iterator it = nums.begin();it!=nums.end();it++){
            //exit
            if(mp.find(*it) != mp.end()){
                mp[*it] ++;
            }
            else{
                mp.insert(make_pair(*it,1));
            }
        }
        int res = 0,t = 0;
        for(map<int,int>::iterator it = mp.begin();it!=mp.end();it++){
            if(it->second > t){
                res = it->first;  
                t = it->second; 
            }
        }
        return res;
    }
};
```