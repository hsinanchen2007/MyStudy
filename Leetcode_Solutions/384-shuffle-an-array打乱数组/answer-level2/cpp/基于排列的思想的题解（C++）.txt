小白一只，未接触过洗牌算法，于是自己想了一个办法，构造方法和reset方法较为简单不再赘述，shuffle方法详解如下。
一个有n个元素的数组，对于第0~n-1个位置，第0个位置有n种情况，第1个位置有n-1种情况，依次递推，第n-1个位置1种情况，一共有n!种排列情况。因此，需要两个数组，result数组来记录结果，visited数组记录原数组的每个位置是否被访问过。
对于result数组的第0~n-1个位置，随机放一个原数组未被访问过的元素，直至result数组的所有位置都有元素。ran是0~n-1的随机数，用来选择原数组的某个位置，若该位置已经被访问过，ran的值更新，直至指向一个未被访问的位置。
```cpp
class Solution {
public:
    vector<int> ini;
    Solution(vector<int>& nums) {
        ini = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ini;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result;
        vector<bool> visited;
        int size = ini.size();
        for(int i=0;i<ini.size();i++){
            visited.push_back(false);
        }
 
        for(int i=0;i<ini.size();i++){
            int ran = rand() % ini.size();
            while(visited[ran]){
                ran = rand() % ini.size();
            }
            visited[ran] = true;
            result.push_back(ini[ran]);
        }
        return result;
    }
};
```
![2.png](https://pic.leetcode-cn.com/0b16bdf686ffe8dc763e014f21d49a23514459dd966925eb10a99e4fcd322386-2.png)
