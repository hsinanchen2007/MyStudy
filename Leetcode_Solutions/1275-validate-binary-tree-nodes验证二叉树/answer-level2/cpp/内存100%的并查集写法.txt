### 解题思路
并查集和一般写法不同，执行merge之后，可能会导致原来合并的元素不再合并。遍历左右子节点数组，如果父子节点在该父子关系之前已经被联通了，则返回false，每执行一次merge，无向连通图的连通分量减一，如果最终连通分量不为1，返回false，再检查一次并查集，若并查集中，有两个元素不连通，则返回false，其余情形返回true。
![image.png](https://pic.leetcode-cn.com/6613bc9a1ee66e9f254d3b04c0ca1a2fd50261f26fb28392bac9b64cf8dc8971-image.png)

### 代码

```cpp
class Solution {
public:
int length;
int f[10001];
void init()
{
    for(int i=0;i<length;i++)
    f[i]=i;
}
int find(int x)
{
    return (x==f[x]?x:f[x]=find(f[x]));
}
void merge(int x,int y)
{
    f[x]=find(y);//此处和以往情况不同
}
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
      length=n;
      init();
      int uni=n;
      for(int i=0;i<leftChild.size();i++)
      {
          if(leftChild[i]==-1)continue;
          if(find(i)==find(leftChild[i]))
          return false;
          merge(leftChild[i],i);
          uni--;
      }
      for(int j=0;j<rightChild.size();j++)
      {
          if(rightChild[j]==-1)continue;
          if(find(j)==find(rightChild[j]))
          return false;
          merge(rightChild[j],j);
          uni--;
      }
      if(uni!=1)
      return false;
      for(int i=1;i<length;i++)
      {
          if(find(i)!=find(0))
          return false;
      }
      return true;
    }
};
```