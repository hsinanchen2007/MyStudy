### 解题思路
此题根据题目所给的一些不符合要求的示例可得出：
    在从根节点开始的递归遍历中，若某节点被遍历到两次，证明不符合。
    若遍历结束后，发现从0-n的节点序列没有被全部遍历，证明也不符合。

### 代码

```cpp
class Solution {
public:
    bool ans=true; //是否符合
    
    void jud(vector<int>& leftChild, vector<int>& rightChild,vector<bool>&re,int n)
    {
        if(re[n]==false) re[n]=true;  //遍历到该节点
        else {ans=false;return ;} //重复遍历到该节点，不符合
        
        if(leftChild[n]!=-1)  //递归遍历
        {
            jud(leftChild,rightChild,re,leftChild[n]);
        }
        if(rightChild[n]!=-1)
        {
            jud(leftChild,rightChild,re,rightChild[n]);
        }
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> re(n,false);
        jud(leftChild,rightChild,re,0);
        vector<bool>::iterator iter=std::find(re.begin(),re.end(),false);
        if(iter!=re.end()) return false;  //看是否遍历了所有节点
        if(ans!=true) return false;  //某节点被遍历了两次
        
        
        return true;
    }
};
```