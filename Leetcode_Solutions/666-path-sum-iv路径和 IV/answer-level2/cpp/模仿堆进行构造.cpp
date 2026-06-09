用数组h记录值，空节点为$-1$，将坐标进行转换，一般来说可以将根的下标当成1，这样左孩子为2，右孩子为3，也就是左孩子为$root<<1$和右孩子为$root<<1|1$，然后使用递归，计算每个节点有多少个叶子节点，该节点就要被加多少次，数组和树均遍历一次，复杂度$O(n)$
```
class Solution {
public:
    int h[100],ans=0;
    int solve(int p){
        if(h[p]==-1)return 0; // 空节点
        if(h[p<<1]==-1&&h[p<<1|1]==-1){ // 叶子节点
            ans+=h[p];
            return 1;
        }
        int t=solve(p<<1)+solve(p<<1|1);
        ans+=h[p]*t; // ans加上该节点的值乘以该节点叶子节点的个数
        return t;
    }
    int pathSum(vector<int>& nums) {
        memset(h,-1,sizeof h);
        for(auto &i:nums){
            int d=i/100;
            int p=(i/10)%10;
            int v=i%10;
            int t=((1<<(d-1))-1+p);
            h[t]=v;
        }
        solve(1);
        return ans;
    }
};
```
