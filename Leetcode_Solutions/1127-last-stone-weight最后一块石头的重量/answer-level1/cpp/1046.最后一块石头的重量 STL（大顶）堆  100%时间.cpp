### 解题思路
此处撰写解题思路
堆的实现在algorithm头文件中
要依托于容器vector或list
注意堆的push pop与 vector的push pop 结合使用
不过内存消耗只排到了5%，优点感人


本题还可以用优先队列做，不过应该没这么快


### 代码

```cpp
#include <vector>
#include <algorithm>

//采用STL，大顶堆

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //建立大顶堆
        make_heap(stones.begin(), stones.end(), less<int>());
        while(stones.size() != 0 && stones.size() != 1){
            //获取最大的
            int stones_1st = * stones.begin();
            //删除堆顶元素
            pop_heap(stones.begin(), stones.end(), less<int>());
            stones.pop_back();
            //获取第二大的
            int stones_2nd = * stones.begin();
            //删除堆顶元素
            pop_heap(stones.begin(), stones.end(), less<int>());
            stones.pop_back();
            
            if(stones_1st != stones_2nd){
                //插入元素
                stones.push_back(stones_1st - stones_2nd);
                push_heap(stones.begin(), stones.end(), less<int>());
            }
        }

        if(0 == stones.size()){
            return 0;
        }else{
            return *stones.begin();
        }




    }
};
```