深度优先遍历判断是否成环 + 环方向判断
![捕获.PNG](https://pic.leetcode-cn.com/f660b9f47527bd71f48ac7d5425020db51c0c69230b7e731273640c8b301234d-%E6%8D%95%E8%8E%B7.PNG)

```
#define NOTUSED -1
#define USING 0
#define USED 1
class Solution {
public:
    bool flag = false;

    int direction = 0; //保存遍历的方向，向后-1，向前1，0为初始情况
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        int* visited = new int[n];
        fill(visited, visited + n, NOTUSED);
        for (int i = 0; i < n and !flag; i++) {
            if (visited[i] == -1) {
                direction = 0;
                dfs(nums, visited, i);
            }  
        }
        return flag;
    }
    void dfs(vector<int>& nums, int* visited, int start) {
        int n = nums.size();
        visited[start] = USING;
        if ((direction > 0 and nums[start] < 0) or (direction < 0 and nums[start] > 0)) {
        //如果此时方向与之前的方向不同，不能直接设置为USED，应该设为NOTUSED，因为这个点可能是环中的一个节点
            visited[start] = NOTUSED; 
            return;
        }
        direction = nums[start] > 0 ? 1 : -1;
        int next = (start + nums[start]) % n;next = (next + n) % n;
        if (visited[next] == NOTUSED) {
            dfs(nums, visited, next);
        }
        else if(next != start and visited[next] == USING){ // next != start用于排除自环
            flag = true;
        }
        visited[start] = USED;
    }
};
```
