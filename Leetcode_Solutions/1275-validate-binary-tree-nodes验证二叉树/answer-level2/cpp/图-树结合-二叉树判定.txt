### 解题思路
1.入度为0的结点只有一个，即根结点，如果超过一个即不是二叉树
2.我们维护一个变量slot,初始为2（根结点提供的两个槽），当判断某个结点时，左孩子不为-1，则出现两个槽可以放结点，如果为-1,则不会增加放结点的槽，右孩子也一样判断，另外每判断完一个结点槽减一，因为他自己占了一个槽。
3.任意时刻slot<0就不是二叉树。
4.如果slot==0但是结点还没判断完说明图非连通。
5.这题要看成图来做，因为没有规定0号结点就是根结点，所以要找出根结点，从其开始判断。因为比如从某个叶子结点开始，左右结点都为-1，slot一次判断之后变为0，但是还有结点没判断，判定为非联通，这样就不对了。

### 代码

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int slot=2,flag=0;
        vector<int>node(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) {
                if (node[leftChild[i]] + 1 != 1)return false;
                else node[leftChild[i]] = 1;
            }
            if(rightChild[i]!=-1){
                if(node[rightChild[i]]+1!=1)return false;
                else node[rightChild[i]]=1;
            }
        }
        vector<int>::iterator root;
        if(count(node.begin(),node.end(),0)!=1)return false;
        for(int i=0;i<n;i++){
            if(node[i]==0){//把根结点放到第一个
                swap(leftChild[0],leftChild[i]);
                swap(rightChild[0],rightChild[i]);
                break;
            }
        }
        for(int i = 0;i<n;i++){
            if(leftChild[i]==-1){slot--;}
            else slot++;
            if(rightChild[i]==-1){slot--;}
            else slot++;
            if(slot<0){return false;}
            if(slot==0&&i!=n-1){return false;}
        }
        return slot==0;
    }
};
```