### 解题思路
遍历节点，碰到第一个不等于根节点的值便保存。
分别用快排、借用map自动排序、借用set自动排序。
找出除去根节点外的最小值，即为所求。
### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getValue(TreeNode* root, int val)
    {
        if (root == NULL)
            return;
        if (root->val == val)
        {
            getValue(root->left, val);
            getValue(root->right, val);
        }
        else
        {
            m_val.push_back(root->val);
            return;
        }
    }
    void quickSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;
        int i = left;
        int j = right;
        int base = nums[left];
        while (i < j)
        {
            while (i < j && nums[j] >= base)
                j--;
            while (i < j && nums[i] <= base)
                i++;
            if (i < j)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        nums[left] = nums[j];
        nums[j] = base;
        quickSort(nums, left, j-1);
        quickSort(nums, j+1, right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL)
            return -1;
        //获取从根节点到叶子节点，所有第一个不等于根节点的值
        getValue(root, root->val);
        //快速排序求出最小值
        if (m_val.size() == 0)
            return -1;
        quickSort(m_val, 0, m_val.size()-1);
        return m_val[0];
        //map自动排序求出最小值
        map<int, int> m;
        for (int i=0; i<m_val.size(); i++)
        {
            m[m_val[i]] = 1;
        }
        map<int, int>::iterator mm;
        mm = m.begin();
        return mm->first;
        //set自动排序求出最小值
        set<int> s;
        for (int i=0; i<m_val.size(); i++)
            s.insert(m_val[i]);
        set<int>::iterator ss;
        ss = s.begin();
        return *ss;
    }
private:
    vector<int> m_val;
};
```