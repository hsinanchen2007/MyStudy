## 思路
+ 遍历`list1`，建立一个哈希表，将字符串映射为索引（和其他做法一样）
+ 建立一个新的哈希表，但是**不是存放list2的字符串索引映射**。
+ 遍历`list2`，当字符串在第一个哈希表当中的时候，这个新的哈希表添加这个字符串，更新它的值为第一个哈希表中的值加上在`list2`里的下标。
+ 遍历第二个哈希表，找到最小的索引和，并更新答案。

## 代码
```c++
#include<unordered_map>
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map;
                
        for (int i = 0; i < list1.size(); i ++){
            map[list1[i]]= i;
        }

        unordered_map<string,int> ans;
        for (int i = 0; i < list2.size(); i ++){
            if (map.count(list2[i]) > 0){
                ans[list2[i]] = map[list2[i]] + i;
            }
        }
        
        vector<string> res; 
        int minin = 9999;
        for (auto i = ans.begin();i != ans.end();i ++){
            if (i -> second < minin){
                res.clear();
                minin = i -> second;
                res.push_back(i -> first);
            }else if (i -> second == minin){
                res.push_back(i -> first);
            }
        }
        return res;
    }
    
};

```