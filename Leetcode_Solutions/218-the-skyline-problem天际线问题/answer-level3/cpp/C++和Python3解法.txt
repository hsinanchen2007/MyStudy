```
/*使用优先队列aliveBuilds<height,rightBound>存储仍可能影响后续天际线处理的building(其右边界大于后续处理buildings的左边界)
  cur_X表示可能的拐点(迭代时初始值为aliveBuilds队首元素的右边界)
  cur_H表示拐点的高度
  依次处理buildings中的所有元素
  如果cur_X小于正在处理的元素的左边界,则表示该队首元素不会影响到后续的拐点处理,依次将优先队列中所有右边界小于当前处理元素左边界的队列成员弹出
  如果cur_X大于正在处理的元素的左边界,则将拐点更新为目前正在处理的元素的左边界,并将该元素的pair<height,rightbound>入队列,若buildings中存在左边界相同的元素,则同样入队列
  cur_H更新为目前优先队列队首元素的高度
  如果cur_H与result中尾部元素的高度不相等,则将pair<cur_X,cur_H>插入结果集中(输出天际线中不得有连续的相同高度的水平线)*/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        int cur = 0, cur_X = 0, cur_H = -1, length = buildings.size();
        priority_queue<pair<int, int>> aliveBuilds;
        while(cur<length || !aliveBuilds.empty())
        {
            cur_X = aliveBuilds.empty() ? buildings[cur][0] : aliveBuilds.top().second;
            if(cur>=length || buildings[cur][0]>cur_X)
            {
                while(!aliveBuilds.empty() && (aliveBuilds.top().second<=cur_X))
                    aliveBuilds.pop();
            }
            else
            {
                cur_X = buildings[cur][0];
                while(cur<length && buildings[cur][0]==cur_X)
                {
                    aliveBuilds.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = aliveBuilds.empty() ? 0 : aliveBuilds.top().first;
            if(result.empty() || (result.back().second!=cur_H))
                result.push_back(make_pair(cur_X, cur_H));
        }
        return result;
    }
}; 
```
```
from heapq import heappush, heappop

class Solution:
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        # 每个building的左边界作为起点事件插入list中
        # 每个building的右边界作为结束事件插入list中
        # list按照左边界从小到大, 高度从大到小, 右边界从小到大排序
        events = [(L,-H,R) for L, R, H in buildings]
        events += list({(R, 0, 0) for _, R, _ in buildings})
        events.sort()
        
        # result保存结果
        result = [(0,0)]
        # alive保存仍会影响后续天际线的buildings
        alive = [(0,float("inf"))]
        for pos, negH, R in events:
            while alive[0][1] <= pos:
                # 将已不会影响后续天际线处理的building弹出heap
                heappop(alive)
            if negH:
                # 如果是新加入的building则将building的高度和右边界入堆
                heappush(alive, (negH, R))
            if result[-1][1] != -alive[0][0]:
                result += [[pos, -alive[0][0]]]
        return result[1:]
```


