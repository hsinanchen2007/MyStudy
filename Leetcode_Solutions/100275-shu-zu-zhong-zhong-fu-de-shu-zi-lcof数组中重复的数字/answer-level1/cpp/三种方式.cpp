### 鸽巢原理（抽屉原理）
把n+1个物体放进n个盒子中，一定有至少一个盒子中有多个物体
原地置换，为了空间复杂度变O(1).这种做法会改变原数组的值
遍历一次，时间复杂度O(N)
```C++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i <= nums.size(); i++){
            int temp=nums[i];
            if(temp >nums.size() || temp<0){
                return -1;
            }
            while(temp!= i){
                if(nums[temp] == temp) return temp;
                swap(nums[i], nums[temp]);
            }
        }
        return -1;
    }
};
```

### unordered_set
 底层用hash存储,插入、查找时间复杂度为O(1)
 注意c++中的set是红黑树存储插入、查找时间复杂度为O(logn)
 此题解空间复杂度 O(n)
```C++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> sets;
        for(int i = 0; i <=nums.size(); i++){
            auto ret = sets.insert(nums[i]);
            if(!ret.second){
                return nums[i];
            }
        }
        return -1;
    }
};
```

### bool数组 
 新建一个bool数组，长度为输入数组的长度
 空间复杂度O(n) 时间复杂度O(n)
```C++
class Solution{
    public:
    int findRepeatNumber(vector<int>& nums) {
        const int sizes = nums.size();
        bool flags[sizes];
        int n = -1;
        memset(flags, false, sizes);
        for(int i = 0; i < sizes; i++){
            n = nums[i];
            if(flags[n]) return n;
            flags[n] = true;
        }
        return -1;
    }
};
```


