涉及第K大/小；前K大/小的 问题通常用堆可以解决

定义一个堆，堆顶为堆中最大元素，维持堆的长度为k
遍历矩阵，如果堆顶元素大于matrix[i][j], 将堆顶元素替换为matrix[i][j]
最后输出堆顶元素即为k小元素
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, less<int>> pq; // 堆顶为最大元素
        int i;
        int j;
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix[0].size(); j++) {
                if (pq.size() < k) {
                    pq.push(matrix[i][j]);
                }
                else if (pq.top() > matrix[i][j])
                {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
                

            }
        }
        return pq.top();
    }
};