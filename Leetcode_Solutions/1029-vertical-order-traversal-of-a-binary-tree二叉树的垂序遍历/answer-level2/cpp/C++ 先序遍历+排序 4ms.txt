
![image.png](https://pic.leetcode-cn.com/8e076d972c721ec8eb743af9048d076b5940db154e5260f2f112be7b011c66cf-image.png)
思路：
step 1：先序遍历过程中生成每个节点的坐标，生成原则：对位于 (X, Y) 的每个结点而言，其左右子结点分别位于 (X-1, Y-1) 和 (X+1, Y-1)。见VisitTreeNode中实现
step 2：根据生成坐标结果进程排序，1）如果两个结点位置相同，则首先报告的结点值较小；2）从上到下的顺序报告结点的值（Y 坐标递减）；3）默认根据升序排序
step 3：整合结合，对于x相同的结果保存在同一个vector中

代码块
```
class Solution {
public:
    void VisitTreeNode(int x, int y, TreeNode* root, vector<vector<int>>& srcData)
    {
        if (root == nullptr) {
            return;
        }
        srcData.push_back({x, y, root->val});
        if (root->left != nullptr) {
            VisitTreeNode(x - 1, y - 1, root->left, srcData);
        }
        if (root->right != nullptr) {
            VisitTreeNode(x + 1, y - 1, root->right, srcData);
        }
    }

    void PushSubResult(vector<vector<int>>& result, vector<int>& subResult)
    {
        if (subResult.empty()) {
            return;
        }
        result.push_back(subResult);
        subResult.clear();
    }

    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>> srcData;
        VisitTreeNode(0, 0, root, srcData);
        sort(srcData.begin(), srcData.end(), [](const vector<int>& v1, const vector<int>& v2) {
            // 如果两个结点位置相同，则首先报告的结点值较小
            if (v1[0] == v2[0] && v1[1] == v2[1]) {
                return v1[2] < v2[2];
            }
            // 从上到下的顺序报告结点的值（Y 坐标递减）
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        });
        vector<vector<int>> result;
        vector<int> subResult;
        subResult.push_back(srcData[0][2]);
        vector<int> continueData;
        int X = srcData[0][0];
        for (int i = 1; i < srcData.size(); ++i) {
            if (X == srcData[i][0]) {
                subResult.push_back(srcData[i][2]);
                continue;
            }
            PushSubResult(result, subResult);
            X = srcData[i][0];
            subResult.push_back(srcData[i][2]);
        }
        PushSubResult(result, subResult);
        return result;
    }
};
```


