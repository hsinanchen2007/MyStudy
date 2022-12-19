解题思路：
1. 用一个map（python中为dict）存储每个数及出现次数。
2. 对所有的keys按从小到大排序；
3. 从左到右遍历keys，右边设一个指针，从右到左，查找符合条件的值（即所有的键存在且引用的次数小于等于本身有的个数）。

伪代码如下：
- left_key = 0, right_key = keys[len(dict) - 1]
- center_key = 0 - left_key - right_key
- while判断条件 left_key<= right_key and left_key + 右边key值\*对应value+ max(0, 右边key值的前一个\*对应value) >= 0
- 判断条件简化： left_key<= right_key and center_key <= right_key # 由于按顺序，因此中间值大于右边值说明已经有重复了
- dict[left_key] = 0  # 左边值清零，防止 出现 0，-1，1这种情况

实际效率python写法与排序加双指针差不多，c++较慢（注意map边界）。
代码如下
```python [] 
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        dic = {}
        for i in range(len(nums)):
            if nums[i] in dic:
                dic[nums[i]] += 1
            else:
                dic[nums[i]] = 1
        keys = sorted(dic.keys())  # map键值排序
        result = []
        left = 0
        while left<len(dic) and keys[left]<=0:  # 左边值大于0就不必判断了
            
            dic[keys[left]]-=1  # 左边键个数减一
            right = len(dic)-1
            second_key = 0-keys[left]-keys[right] # 中间键值
            while left<=right and second_key<=keys[right]: 
                dic[keys[right]]-=1  # 先减一，防止重用
                if dic.get(second_key, 0)>0:
                    result.append([keys[left], second_key,keys[right]])
                
                dic[keys[right]]+=1  # 加回去，恢复现场
                right -= 1 
                second_key = 0-keys[left]-keys[right]
        
            dic[keys[left]] = 0   # 用过的去掉，防止重复使用如【0 -1， 1】， 也可以在添加的时候判断三者不下降。
            left+=1
```
```c++ []
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        map<int,int> intMap;
        map<int,int>::iterator iterL,iterR, iterC;
        for (int i=0;i<nums.size();i++) {
            if (intMap.count(nums[i]) == 0)
                intMap[nums[i]] = 1;
            else
                intMap[nums[i]] += 1;
        }
        
        for(iterL = intMap.begin(); iterL != intMap.end() && iterL->first<=0; iterL++) {
            iterL->second--;
            //cout<< iterL->first<<" "<< iterL->second <<endl;  
            iterR = intMap.end();  // 不能写成intMap.end()--; 要拆成两句。
            iterR--;
            //cout<<"r: "<< iterR->first<<" "<<iterR->second<<endl;
            int center_key = 0 - iterL->first - iterR->first;
            while (iterL->first<=iterR->first && center_key <= iterR->first) {
                iterR->second--;  // 右边值减一
                iterC = intMap.find(center_key);
                if (iterC!=intMap.end() && iterC->second>0) {
                    result.push_back(vector<int>{iterL->first, center_key, iterR->first});
                }
                iterR->second++; // 右边值加一
                if (iterL==iterR)  // 边界情况
                    break;
                iterR--;
                center_key = 0 - iterL->first - iterR->first;
            }
            iterL->second = 0;
        }
        return result;  
    }
};
```


