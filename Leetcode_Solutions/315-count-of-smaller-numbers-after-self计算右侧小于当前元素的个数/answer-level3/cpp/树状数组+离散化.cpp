使用树状数组，反着插入，求前缀和即可，但因为数据没规定正负，于是需要离散化一下再重新排序一下，但是看case貌似是正的比较多啊。
这种方法速度慢在两次排序。另外当两个值相同的时候index小的排在前面，不然相同的数据会出问题（因为离散化之后每个点的权值都是不同的）。
树状数组在求康托排列时也可以非常好的运用。
这题使用树状数组的缺点：常数过大。
*复杂度：O(nlogn)*（一次扫描，O(n)，两次排序分别是O(nlogn)，查询每次是O(logn)，共n次）
```
class Solution {
public:
#define lowbit(x) ((x)&(-x))
    struct node {
        int v,index1,index2;
        node(int v,int i1,int i2):v(v),index1(i1),index2(i2){}
    };
    void modify(vector<int> *c,int x,int n){
        for(;x<=n;x+=lowbit(x)){
            ++(*c)[x];
        }
    }
    int getsum(vector<int> *c,int x){
        int ret=0;
        for(;x;x-=lowbit(x)){
            ret+=(*c)[x];
        }
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<node> temp;
        for(int i=0;i<n;++i){
            temp.push_back(node(nums[i],i,0));
        }
        sort(begin(temp),end(temp),[](node &a,node &b) {
            if(a.v==b.v)return a.index1<b.index1;
            return a.v<b.v;
        });
        for(int i=0;i<n;++i){
            temp[i].index2=i+1;
        }
        sort(begin(temp),end(temp),[](node &a,node &b) {
            return a.index1<b.index1;
        });
        // for(auto &i:temp){
        //     printf("%d ",i.index2);
        // }
        vector<int> c(n+1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;--i){
            modify(&c,temp[i].index2,n);
            ans[i]=getsum(&c,temp[i].index2-1);
        }
        return ans;
    }
};
```
