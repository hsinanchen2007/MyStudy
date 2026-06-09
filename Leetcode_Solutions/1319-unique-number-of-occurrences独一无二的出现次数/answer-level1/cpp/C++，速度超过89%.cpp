#### 解题思路
map映射记录元素出现次数，再排序查看是否有重复元素即可

### 代码
//时间复杂度O(nlog2n)，空间复杂度O(n)
```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int *map = new int[2001](); //记录每个元素出现的次数
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] >=0 ) //0和正整数
                map[arr[i]]++;
            else
            //对于小于0的负数，将其加上2001后进行映射
                map[arr[i]+2001]++; 
        }
        //调用排序算法对map进行排序
        sort(map, map+2001);
        //查找map中是否有重复出现的数字（即每个元素出现的次数是否相同）
        for(int i = 0; i < 2000; i++){
            if(map[i] !=0 && map[i] == map[i+1])
                return false;
        }
        return true;
    }
};
```