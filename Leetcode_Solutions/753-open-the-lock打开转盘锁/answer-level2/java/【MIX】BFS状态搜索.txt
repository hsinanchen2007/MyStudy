```c++ []
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 将vector转为set存储
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        // set<string> deadset(deadends.begin(), deadends.end());
        
        // 判断特殊情况
        if("0000" == target)
            return 0;
        if(deadset.find("0000") != deadset.end())
            return -1;
        if(deadset.find(target) != deadset.end())
            return -1;
        
        // 建立bfs辅助队列
        queue<string> q;
        q.push("0000");

        // 建立访问映射, 存储访问记录和步数
        map<string, int> visited;
        visited["0000"] = 0;

        // bfs循环
        while(!q.empty()){
            string cur = q.front();
            q.pop();

            unordered_set<string> stats;
            // 存储下一步状态
            for(int i=0; i<cur.size(); ++i){
                // 存储前向后向波动
                string n1 = cur, n2 = cur;
                n1[i] = n1[i]=='9'?'0':n1[i]+1;
                n2[i] = n2[i]=='0'?'9':n2[i]-1;
                stats.insert(n1);
                stats.insert(n2);
            }
            // 对下一步状态进行遍历
            for(string stat: stats){
                if(deadset.find(stat) == deadset.end() && visited.find(stat) == visited.end()){
                    map<string, int>::iterator mit = visited.find(cur);
                    // 合理密码加入访问映射中
                    visited[stat] = mit->second+1;
                    q.push(stat);
                    // 判断是否达到解锁条件
                    if(stat == target){
                        auto mit = visited.find(target);
                        return mit->second;
                    }
                }
            }
        }

        return -1;
    }
};
```
```python []
from queue import Queue
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        # 特殊情况处理
        if target == "0000":
            return 0
        # 转为set存储
        deadends = set(deadends)
        if "0000" in deadends:
            return -1
        if target in deadends:
            return -1

        # bfs算法求解无权图的最短路径
        # 使用队列存储访问的密码
        q = Queue()
        q.put("0000")
        # 记录密码和操作步骤的字典
        visited = {"0000" : 0}
        while q.empty() is False:
            cur = q.get()
            
            # 存储之后的状态
            stats = set()
            # 将String分解为字符list
            cur_list = list(cur)
            
            # 可能状态存储
            for i in range(cur_list.__len__()):
                # 保留原来的字符
                o = cur_list[i]
                
                # 密码向后波动1位
                cur_list[i] = str((int(cur_list[i])+1) % 10)
                stats.add(''.join(cur_list))
                
                # 还原
                cur_list[i] = o

                # 密码向前波动1位
                cur_list[i] = str((int(cur_list[i])+9) % 10)
                stats.add(''.join(cur_list))

                # 还原
                cur_list[i] = o
            
            # 可能状态遍历
            for stat in stats:
                if stat not in deadends and stat not in visited.keys():
                    q.put(stat)
                    visited[stat] = visited[cur]+1
                    # 如果为target则返回
                    if stat == target:
                        return visited[stat]
        return -1
```
```java []
public class Solution{
	public int openLock(String[] deadens, String target){
		// 使用HashSet建立deadset结构, 加快查询速度
		HashSet<String> deadset = new HashSet<>();
		for(String s: deadends)
			deadset.add(s);

		// 当目标数字包含在deadset中, 无法打开
		if(deadset.contains(target))
			return  -1;
		
		// 当起始数字包含在deadset中, 无法打开
		if(deadset.contains("0000"))
			return -1;

		// 起始状态=终止状态
		if(target.equals("0000"))
			return 0;

		// BFS
		Queue<String> queue = new LinkedList<>();
		queue.add("0000");

		// 建立visited的映射, 表示已经访问过的序列
		// 同时存储密码和步骤
		HashMap<String, Integer> visited = new HashMap<>();
		visited.put("0000", 0);
		
		while(!queue.isEmpty()){
			String curs = queue.remove();
			// 将String转化为char[], 对每一位进行操作
			char[] cur_array = curs.toCharArray();
			// 下一步的可能转移到的状态
			ArrayList<String> nexts = new ArrayList<>();
			// 存储波动后的可能状态
			for(int i=0; i<cur_array.length; ++i){
				// 存储原始数字
				char o = cur_array[i];
				// 数字向后拨1位
				cur_array[i] = Character.forDigit((cur_array[i] - '0' + 1) % 10, 10);
				// 加入到可能的状态列表中
				nexts.add(new String(cur_array));
				
				// 还原
				cur_array[i] = o;

				// 数字向前拨1位, 考虑到负数的可能性
				cur_array[i] = Character.forDigit((cur_array[i] - '0' +9) % 10, 10);
				nexts.add(new String(cur_array));
				
				// 还原
				cur_array[i] = o;
			}
			

			for(String next: nexts)
				// 下一个状态不包括在deadset中且没有被访问过
				if(!deadset.contains(next) && !visited.containsKey(next)){
					queue.add(next);
					visited.put(next, visited.get(curs)+1);
					if(next.equals(target))
						return visited.get(next);
				}
		}
		return -1;
	}
}
```
c++版本参考了**@yangdong的C++ BFS**版本的部分代码