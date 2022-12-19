```
class Solution {
private:
    struct node{
        int index;
        int val;
    };
    struct cmpp {
        bool operator() (node& a, node& b) {
            return a.val>b.val;
        }
    };
public:
    int maxJumps(vector<int>& arr, int d) {
        priority_queue<node, vector<node>, cmpp> q;  //先计算当前高度最小的，其他高度依赖最小高度的可占用index
        int len=arr.size();
        for(int i=0;i<len;i++) {
            node t;
            t.index=i;
            t.val=arr[i];
            q.push(t);
        }
        int res=1;
        vector<int> dp(len,1);
        while(!q.empty()) {
            node cur=q.top();
            q.pop();
            int pos=cur.index;
            int val=cur.val;
            bool add=true;
            bool sub=true;
            for(int step=1;step<=d;step++) {
                if(pos+step<len&&add) {
                    if(arr[pos+step]>=val) {
                        add=false;
                    }else {
                        if(dp[pos+step]+1>dp[pos]) {
                            dp[pos]=dp[pos+step]+1;
                        }
                    }
                }
                if(pos-step>=0&&sub) {
                    if(arr[pos-step]>=val) {
                        sub=false;
                    }else {
                        if(dp[pos-step]+1>dp[pos]) {
                            dp[pos]=dp[pos-step]+1;
                        }
                    }
                }
                if(!add&&!sub) {
                    break;
                }
            }
            if(dp[pos]>res) {
                res=dp[pos];
            }
        }
        return res;
    }
};
```
