方法一：并查集
使用并查集存储当前节点的父节点，其中父节点为当前节点+1值，或者经过中间多个连续父节点的传递。例如：3->4->5->6，3的父节点可以是4,5,6的任意一个；当无法继续传递时，父节点为自身，即6的父节点为6。将所有节点**并**入到其父节点中，任意给出一个节点x，**查**找其最终的父节点f,则[x,f]必然是连续的，其长度为f-x+1。
```
// Time 24ms, Space 10MB
class Solution {
    int father(unordered_map<int,int> &F, int x){
        if(F.count(x)==0) return x;
        for(; F[x]!=x; x=F[x]);
        return x;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> F;
        for(const int &x:nums){
            if(x!=INT_MAX && F.count(x+1)) F[x]=father(F,x+1);
            else F[x]=father(F,x);
            if(x!=INT_MIN && F.count(x-1)) F[x-1]=F[F[x]];
        }
        int len=0;
        for(const int &x:nums)
            len=max(len,father(F,x)-x+1);
        return len;
    }
};
```

方法二：哈希表
使用哈希存储所有节点，任意给出一个节点x，查找其父节点x+1是否在哈希中，如果在，继续查找x+2，直到x+n不存在哈希中时，则[x,x+n-1]必然连续且存在，其长度为n。如果该节点x的孩子x-1在哈希中，则跳过，因为总会遍历到以x-1为起始节点的连续值。
```
// Time 16ms, Space 9.1MB
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict(nums.begin(),nums.end());
        int len=0;
        for(const int &a:nums){
            if(a!=INT_MIN && dict.count(a-1)) continue;
            int right=0, i=a;
            for(; i!=INT_MAX && dict.count(i); ++i, ++right);
            len=max(len,right+(dict.count(i)?1:0));
        }
        return len;
    }
};
```
