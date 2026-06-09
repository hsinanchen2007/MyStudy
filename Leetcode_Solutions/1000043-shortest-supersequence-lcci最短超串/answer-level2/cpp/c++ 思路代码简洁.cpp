# Hash+数组+滑动窗口

首先哈希表m存储small中的元素，便于查找，使用滑动窗口[l,r]来遍历big,用一个数组vis记录当前滑动窗口包含的small各元素的次数，一个变量cnt记录当前窗口中包含的small中元素的个数，滑动窗口工作规则如下：
1.判断big[r]是否为small中元素，若不是，r++。
2.否则修正vis的值，并判断是否为新加入的small元素，更新cnt。
3.判断cnt与small数组的大小，若cnt=small.size,表明此时滑动窗口包含所有small中的元素，因此递增l直到满足vis[big[l]]为1，即此时滑动窗口最小，更新长度和左右区间。

时间复杂度O(n),空间复杂度O(n),n为small长度
代码如下：
```
class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        int n = small.size();
        vector<int> vis(n,0);
        int b = big.size();
        int l = 0,r = 0,cnt = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)m[small[i]]=i;
        int ansl=-1,ansr = -1,len = INT_MAX;
        while(r<b){
            if(m.count(big[r])==0){r++;continue;}
            if(vis[m[big[r]]]==0)cnt++;
            vis[m[big[r]]]++;
            if(cnt==n){
                while(l<=r){
                    if(m.count(big[l])==0){l++;continue;}
                    vis[m[big[l]]]--;
                    if(vis[m[big[l]]]==0){
                        if(len>r-l+1){
                            ansl = l;ansr=r;
                            len = r-l+1;
                        }
                        cnt--;
                        l++;
                        break;
                    }
                    l++;
                }
            }
            r++;
        }
        vector<int> ans;
        if(len<INT_MAX){ans.push_back(ansl);ans.push_back(ansr);}
        return ans;
    }
};

```

疑惑点：滑动窗口和同端双指针的区别，希望各位大佬在评论区进行点拨。

