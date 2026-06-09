真正的面试中不太可能亲自实现一个堆，这个时间成本有点高。
但我这边好久没写过堆的算法了，所以手痒亲自写了一个。
```
class Solution {
private:
    unordered_map<int, int> g_nums_map;
    bool g_is_head_sorted = false;
public:
    /*
        这种题目的核心思路在于维护一个最大或者最小堆，这个堆的大小刚好就是k
        堆顶为极值，如果新元素大于或者小于这个极值，就往替换极值，并且更新.
    */

    void update_heap(vector<int>& heap, int pos, int last_pos) {
        //更新的位置 0, 1, 2, 3
        int dad = pos;
        int son = dad * 2 + 1;
        while (son <= last_pos) {
            if (son + 1 <= last_pos and 
                g_nums_map[heap[son + 1]] < g_nums_map[heap[son]]) {
                //最小堆，父亲应该小于子节点，取子节点中最小的
                ++son;
            }
            if (g_nums_map[heap[son]] < g_nums_map[heap[dad]]) {
                int temp = heap[son];
                heap[son] = heap[dad];
                heap[dad] = temp; 
            }
            else {
                break;
            }
            dad = son;
            son = dad * 2 + 1;
        }
        
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            if (g_nums_map.count(nums[i]) == 0) {
                g_nums_map.insert(pair<int, int>(nums[i], 1));
            }
            else {
                g_nums_map[nums[i]] = g_nums_map[nums[i]] + 1;
            }
        }
        vector<int> result;
        unordered_map<int, int>::iterator map_iter = g_nums_map.begin();
        while(map_iter != g_nums_map.end()) {
            if (result.size() != k) {
                result.push_back(map_iter->first);
            }
            else {
                if (g_is_head_sorted == false) {
                    //没有初始化，就需要初始化，然后再替换头部节点
                    //0 - 最后一个父亲节点 0,1,2,3,4,5,6
                    int last_father_node_pos = (k - 1) / 2;
                    for (int i = last_father_node_pos; i >= 0; --i) {
                        update_heap(result, i, k - 1);
                    }

                    g_is_head_sorted = true;

                }
                if (map_iter->second > g_nums_map[result[0]]) {
                    result[0] = map_iter->first;
                    update_heap(result, 0, k - 1);
                }

            }
            ++map_iter; 
        }

        for (int i = result.size() - 1; i >= 0; --i) {
            //把堆顶结果个最后一个替换，同时把最后一个删掉，然后更新堆
            int temp = result[i];
            result[i] = result[0];
            result[0] = temp;
            update_heap(result, 0, i - 1);
        }
        return result;
    }
};
```


