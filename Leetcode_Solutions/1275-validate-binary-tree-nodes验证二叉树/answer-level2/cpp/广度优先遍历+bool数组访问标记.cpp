30ms 30MB
队列广度优先遍历
由于节点数是0-n-1，用bool数组代替哈希表
通过队列遍历判断节点是否访问过
最后遍历bool数组查看是否有未访问过的节点
```
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        bool flag[n];
        memset(flag,false,n);
        deque<int> x;
        int i=0;
        x.push_back(0);
        while(!x.empty()){
            i=x[0];
            x.pop_front();
            if(flag[i]) return false;
            else flag[i]=true;
            if(leftChild[i]!=-1)
                x.push_back(leftChild[i]);
            if(rightChild[i]!=-1)
                x.push_back(rightChild[i]);                
        }
        for(auto c : flag){
            if(!c) return false;
        }
        return true;
    }
};
```
