借助树的层次遍历的思想，要成为一棵树 要满足下面两点
1.目前层不能指向上一层，使用`visit`数组来判重
2.在目前层给下一层压入队列的时候，不能压入同一个节点（会形成环），使用set来判重
```
 bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>> mp;
        queue<int> q;
        q.push(0);
        unordered_set<int> help;
        vector<bool> visit(n,false);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz;i++){
                int a = q.front();
                q.pop();
                visit[a] = true;
                if(leftChild[a]!=-1){
                    if(!visit[leftChild[a]]){ // 指回去不行
                        if(help.find(leftChild[a])==help.end()){
                            q.push(leftChild[a]);help.insert(leftChild[a]);} //给下一层进队不能重复
                        else
                            return false;
                    }
                    else return false;
                }
                if(rightChild[a]!=-1){
                    if(!visit[rightChild[a]]){
                        if(help.find(rightChild[a])==help.end()){
                            q.push(rightChild[a]);help.insert(rightChild[a]);}
                        else
                            return false;
                    }
                    else return false;
                }
                
            }
            help.clear();
        }
        for(auto a : visit)
            if(a == false)
                return false;
        return true;

    }
```
