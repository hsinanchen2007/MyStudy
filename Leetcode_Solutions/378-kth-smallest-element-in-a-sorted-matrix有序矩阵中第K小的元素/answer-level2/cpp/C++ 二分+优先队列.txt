参考了大家的方法，贴一下C++的实现 


### 二分法
**思路**：二分法的常规操作，难点是边界的划分以及理解为什么最终得到的数字在数组中，尝试倒着推一下看是不是好理解些

为了保证两个边界最终收敛于`target`，我们首先要保证`target`始终在左右边界之间，即`left <= target <= right`

得到mid后，统计数组中` <=mid `的数的个数，这里用`cnt`表示`count( <=mid )`，有三种情况

1. `cnt < k`
此时可以判断`mid < target`(note:因此有`mid+1 <= target`)，因此左边界向上靠
想要得到`left <= target`，显然需要`left = mid + 1`;
2. `cnt > k`
此时可以判断`mid > target`，因此右边界向下靠
想要得到`right >= target`，可以取`right = mid - 1`
3. `cnt = k`
此时可以判断`mid >= target`，因此右边界向下靠
为满足条件，需要取`right = mid`

这里整合下2、3条件，可以用在`cnt >= k`时，统一取`right = mid`，放宽了2的边界，仍然保持整体满足`target <= right`  

贴代码
```
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()|| matrix[0].empty()) return -1;

        int row = matrix.size(), col = matrix[0].size();
        int l = matrix[0][0], r = matrix[row-1][col-1];

        while(l < r){ //注意这里的退出条件，不同的取边界方式可能有不同的条件
            int mid = l + (r-l)/2;
            int cnt = 0;
            for(int i=0; i<row; ++i){
                for(int j = 0; j<col && matrix[i][j] <= mid; ++j) cnt++; 
                //既然每行数组是单增的，一个大于mid的数后面的数显然也大于mid，可忽略
                //另外一定要判断<=mid，而不是<mid  
            }
            if(cnt < k) l = mid + 1;
            else r = mid;
        }
        return l; //l和r此时相同，返回r也可以
    }
};
```
  
##### 复杂度
- 时间： O(k*logM)，M为首位两数(最小的数最大的数)的差值
- 空间： O(1)

---

### 优先队列
最简单的方式是按照默认方法维护一个k大小的大顶堆，遍历所有数据就行
```
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto x:matrix){
            for(auto i:x){
                pq.push(i);
                if(pq.size()>k) pq.pop();
            }
        } 
        return pq.top();
    }
};
```
##### 复杂度
- 时间：维护一个容量为k的堆的时间复杂度为O(logk)，因此总复杂度为O(n*logk)
- 空间：O(k)
   

### 另一个思路的优先队列
上面的思路显然没有利用矩阵的有序特点；
拿到这个题目时，最直接的思路，就是定义row个指针，指向每行的开头，每轮取出最小的数，然后该行指针后移，继续比较
但是显然需要比较的次数太多，因此放弃了；
后面看到一个python语言的题解，可以用优先队列代替row个指针的比较过程，降低了不少复杂度，因此复现了C++版；
*note：在k比行数row小的情况下，其实比较前k行就可以了，前k行一定至少有k个大于matrix[k][0]的数*
```
class Solution {
public:
    typedef pair<int, pair<int, int>> int3;
    //基础语法不是很好，又想练下pair的用法；不确定C++中是否可以在优先队列中直接存三个数
    
    class mycomparison
    {
    public:
        mycomparison(){};
        bool operator() (auto& lhs, auto& rhs) const {
            return (lhs.first>rhs.first);
        }
    }; //默认的大顶堆方式，实现小顶堆需要自己定义比较类

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(); 

        priority_queue<int3, vector<int3>, mycomparison> pq;
        
        for(int i=0; i<min(m, k); ++i){ //k比m小时，只需要比较前k行，k个指针就足够
            pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
            //存储的值为(matrix[i][0], i, j),坐标是为了指针后移
        }

        while(--k){
            auto tmp = pq.top(); pq.pop();
            int i = tmp.second.first, j = tmp.second.second + 1; //i保持不变，j后移一位
            if(j < n) pq.push(make_pair(matrix[i][j], make_pair(i, j)));
        }
        return pq.top().first;
    }
};
```
##### 复杂度
- 时间：初始化：O(C)，插值：O(k\*logC)，因此复杂度为O(C + k*logC)，其中C = min(k, m)
- 空间：O(C)
  
 缺点：C++实现如上的优先队列很麻烦；同时虽然理论上的时间负责度还行，但是实际跑的时候奇慢，不知道是不是因为自己定义的comp的缘故


基础很菜的小白，如果有错误的话大家一定要指出啊