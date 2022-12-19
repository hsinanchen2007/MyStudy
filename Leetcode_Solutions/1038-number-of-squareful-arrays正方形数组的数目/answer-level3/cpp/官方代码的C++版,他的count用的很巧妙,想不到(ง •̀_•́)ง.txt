    map<int,int> count;//
    map<int,vector<int>> graph;
    int DFS(int x,int n){
        count[x] -= 1;
        int res;
        if(n == 0){
            res=1;
        }else{
            res=0;
            for(int i=0;i<graph[x].size();i++){
                int y=graph[x][i];
                if(count[y]){
                    res+= DFS(y, n- 1);
                }
            }
        }
        count[x] += 1;
        return res;
    }
    int numSquarefulPerms(vector<int>& A) {
        vector<int> nums;
        for(int i=0;i<A.size();i++){
            if(count.find(A[i])!=count.end()){
                 count[A[i]]++;               
            }else{
                 count[A[i]]=1;
                nums.push_back(A[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                int s=nums[i]+nums[j];
                int a=round(sqrt(s));
                if(a*a==s){
                    graph[nums[i]].push_back(nums[j]);
                }
            }
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            res+=DFS(x, A.size() - 1);
        }
        return res;
    }