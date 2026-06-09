### 解题思路
实现BFS即可解决

### 代码
![图片.png](https://pic.leetcode-cn.com/a74a36e0e5dc3ed3d7b40a75d4e364e344aab1056be6fd08d2a5295f96019763-%E5%9B%BE%E7%89%87.png)

```cpp
class Solution {
public:
	int jump(vector<int>& nums) {
        //队列中所放的元素
		typedef struct {
			int pos;  //当前所在位置
			int step; //到该位置已经走过的步数
			int len;  //当前位置可以走的长度
		}Node;
		vector<Node> queue;
		//将nums[0]作为初始值放入队列中
		Node node = { 0, 0, nums[0] };
		queue.push_back(node);
        int res = 0;
        int *visited = new int[nums.size()]();
		for (int i = 0; i<queue.size(); i++){
			//从队列取元素
			for (int j = queue[i].len; j >=1; j--){
				if ((nums.size() - 1) == (queue[i].pos + j)){
					return queue[i].step + 1;
				}
                //判断下一步到达的位置是否小于nums.size()
                //如果前面已经访问过后面再访问所需的步数肯定不是最小的，所以不需要加入队列了
				if ((queue[i].pos + j < nums.size())&&(0 == visited[queue[i].pos + j])){
				    Node nd = { queue[i].pos + j, queue[i].step + 1, nums[queue[i].pos + j] };
                    visited[queue[i].pos + j] = 1;
				    queue.push_back(nd);
			    }
			}
		}
        return res;
	}
};
```