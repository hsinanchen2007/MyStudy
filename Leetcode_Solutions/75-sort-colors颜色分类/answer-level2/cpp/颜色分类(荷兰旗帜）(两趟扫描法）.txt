
![image.png](https://pic.leetcode-cn.com/b59f88196ac2d431d6518da585557043cafbf45d9ae30aaa4b417a5879f63c0d-image.png)
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
       vector<int> hashMap(3);
       for(int it:nums){
           hashMap[it]++;
       } 
       vector<int>res;
       for(int i=0;i<hashMap.size();++i){
           while(hashMap[i]--){
                res.push_back(i);
           }
       }
       nums=res;
    }
};
```