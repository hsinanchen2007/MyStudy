### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/85dc38f93538efd5b0caac66a7a3778cf01b847145ab0605b36aadd824c3bb37-image.png)

先将数字与小标组合进行排序，然后查找。

### 代码

```cpp
class Numitem{
public:
    Numitem(int a, int b)
            :num(a),
            index(b){};
    
    int num;
    int index;
    
    friend bool operator < (const Numitem a, const Numitem b)
    {
        return a.num < b.num || (a.num == b.num && a.index<b.index);
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        vector<Numitem> numsIndexSort;
        for(int i=0; i<nums.size(); i++){
            numsIndexSort.push_back(Numitem(nums[i],i));
        }
        sort(numsIndexSort.begin(),numsIndexSort.end());
        for(int i=0; i< numsIndexSort.size()-1; i++){
            if(numsIndexSort[i].num==numsIndexSort[i+1].num && numsIndexSort[i+1].index - numsIndexSort[i].index<=k){
                return true;
            }
        }
        return false;
    }
};
```