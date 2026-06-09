### 解题思路
1. 可以采用广度优先搜索思想，类似于二叉树的层次遍历。
2. 创建队列 `iq` 存储可以下一步跳到的下标。创建集合 `visited` 记录访问过的下标。
3. 如果当前下标 `i` 处的元素值为 `0`，返回 `true`，退出程序。
4. 否则，分别判断 `left = i - arr[i]` 和 `right = i + arr[i]` 是否在 `[0, arr.length)` 范围内，并且没有被访问过。
5. 如果是，将 `left` 或 `right` 存储在队列 `iq` 中。（`left` 和 `right` 类似二叉树的左右结点。）
6. 删除 `iq` 中已经处理过的下标 `i`，跳到步骤 3。
7. 如果 `iq` 没有元素了，退出循环，返回 `false`。

### 代码
```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        set<int> visited;   // 记录访问过的下标
        queue<int> iq;      // 存储待处理的下标

        iq.push(start);
        
        while(!iq.empty())
        {
            int i = iq.front(); // 取队列 iq 中的第一个元素作为当前要处理的下标
            if(arr[i] == 0)
                return true;

            visited.insert(i);  // 记录访问过的下标
            
            int left = i - arr[i];
            if(left >= 0 && left < arr.size())
            {
                if(visited.count(left) <= 0)
                    iq.push(left);
            }
            
            int right = i + arr[i];
            if(right >= 0 && right < arr.size())
            {
                if(visited.count(right) <= 0)
                    iq.push(right);
            }
            
            iq.pop();
        }
        
        return false;
    }
};
```


### 复杂度分析
时间复杂度：$O(N)$，其中 $N$ 是 `arr` 的元素个数。平均情况下，运行时间为 $\Theta(\lg N)$。
空间复杂度：$O(N)$。`iq` 和 `visited`。
