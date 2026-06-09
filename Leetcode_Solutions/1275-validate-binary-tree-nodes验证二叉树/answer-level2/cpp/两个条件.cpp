### 解题思路
每个点入度最多为1，边数为n-1
### 代码

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int *father=new int[n];
        int save=0;
        for(int i=0;i<n;i++)
            father[i]=0;
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {father[leftChild[i]]++;save++;}
            if(rightChild[i]!=-1)
            {
                father[rightChild[i]]++;save++;
            }
            if(leftChild[i]!=-1)
            if(father[leftChild[i]]>1)return false;
            if(rightChild[i]!=-1)
            if(father[rightChild[i]]>1)return false;
        }
        return save==n-1;
    }
};
```