### 解题思路
用一个哈希表存储着不同状态的数组，知道出现重复，就知道循环次数
不需要存储整个数组，因为它们就相当于一个 8 位的二进制数，只要转换成对应的十进制值就行了


### 代码

```cpp
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // 
        unordered_map<int, int> m;
        vector<int> temp(8, 0);
        int i = 1;
        while(i <= N) {
            for(int j = 1; j < 7; j++) {
                temp[j] = (cells[j-1]==cells[j+1]);
            }
            temp[0] = 0;
            temp[7] = 0;
            swap(temp, cells); //temp存放的是每次迭代结果,效率比交换要高

            int val = 0;
            for(int j = 0; j < 7; j++) {
                val = val*2+cells[j];  //记录每一次迭代过程中 cells对应的十进制数 val
            }

            if(m.find(val) == m.end()){  //针对键值（十进制数）进行查找，如果找到末尾，说明没有遇到和val重复的
                m[val] = i; //m的键值为val,值为循环轮数i
            }
            else{ // 出现重复
                int cycle_len = i-m[val]; // 循环的长度
                i += (N-i)/cycle_len*cycle_len; // 跳过中间重复的循环部分  中间的i跳过去
            }
            i++;
        }
        return cells;
    }
};
```