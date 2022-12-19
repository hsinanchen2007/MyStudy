先贴代码
```
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int> inDegree(n,0);  //入度
        vector<int> outDegree(n,0); //出度
        vector<int> length(n,0);    //从一点出发的最长路径
        vector<bool> visited(n,false);  //记录点是否访问过
        vector<bool> alived(n,true);    //记录点是否存活
        for(auto i=nums.begin();i!=nums.end();i++){ //计算每个点的入度和出度
            inDegree[*i]++;
            outDegree[distance(nums.begin(),i)]++;
        }
        while(true){
            for(int i=0;i<n;i++)
                if(alived[i]&&inDegree[i]==0){  //删除所有入度为0的点
                    alived[i]=false;
                    inDegree[nums[i]]--;
                }
            bool tempa=true;
            for(int i=0;i<n;i++)
                if(alived[i]&&(inDegree[i]!=1||outDegree[i]!=1))
                    tempa=false;
            //如果所有存活的点的入度和出度都为1，则说明存活点都在环中，此时终止循环
            if(tempa)
                break;
        }
        for(int i=0;i<n;i++){   //计算每一个环路的长度
            if(visited[i]||!alived[i])  //如果该点已经访问过了或者不在环路中，则跳过该点
                continue;
            int tlength=1;
            for(int j=nums[i];j!=i;j=nums[j])   //计算环路长度
                tlength++;
            length[i]=tlength;
            visited[i]=true;
            for(int j=nums[i];j!=i;j=nums[j]){  //标记环路中点的最长路径
                length[j]=tlength;
                visited[j]=true;
            }
        }
        while(true){
            for(int i=0;i<n;i++){
                if(visited[i])
                    continue;
                if(visited[nums[i]]){
                    //如果该点指向的点已被标记，则该点的最长路径长度为其指向的点+1
                    length[i]=length[nums[i]]++;
                    visited[i]=true;
                }
            }
            bool tempa=true;
            for(int i=0;i<n;i++)
                if(!visited[i])
                    tempa=false;
            //如果所有点都已标记，则跳出循环
            if(tempa)
                break;
        }
        int max=0;
        for(int i=0;i<n;i++)    //返回最长路径
            if(max<length[i])
                max=length[i];
        return max;
    }
};
```
在仔细思考这道题的题意之后，我发现其实就是一个有向图寻找最长无环路径的问题。  
这个有向图可能存在着环路，但每条路径最多只能进入一个环路（思考题：为什么？） 
我采用类似拓补排序的方法，将所有入度为0的点删除，剩下的就是环路中的点。而由于每个点只能指向一个其他点，剩下的环路中的点必然出度和入度都为1。
在更新每个环路的长度之后，我们再回头标记所有指向已标记点的最长路径长度。在我的代码中我使用了while循环，这里如果牺牲部分空间，建立一个链表指向父节点可以大大提升效率。