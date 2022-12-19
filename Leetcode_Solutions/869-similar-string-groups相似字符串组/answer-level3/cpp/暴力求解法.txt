    class Solution {
    public:
        int n=0;
        bool xiangshi(string a,string b){//判断相似
            int k=0;
            if(a==b)return true;
            for(int i=0;i<a.length();++i){
                if(k==3)return false;
                if(a[i]!=b[i])k++;
            }
            if(k==2){
                return true;
            }
            return false;
        }
        int H(int i,vector<int> &bing){//求并查集的根
                while(bing[i]!=i){
                i=bing[i];
                }
                return i;
        }
        int numSimilarGroups(vector<string>& A){
            vector<int> bing;//并查集数组
            int n=A.size();
            for(int i=0;i<n;++i){
                bing.push_back(i);
            }
            int k=0;
            for(int i=0;i<n-1;++i){
            
                for(int j=i+1;j<n;++j){//遍历所有的两两相似组
                    if(xiangshi(A[i],A[j])&&H(j,bing)!=H(i,bing)){//相似且不属于一个组
                        if(bing[j]!=j){//如果j属于另外的组合并两组
                            bing[H(j,bing)]=i;
                        }
                        else{//属于根结点直接指向i
                            bing[j]=i;
                        }
                    }
                }
                
            }
            
            for(int i=0;i<n;i++){//查找相似组个数
                if(bing[i]==i)k++;
                    
            }
            return k;
        }
        
    };