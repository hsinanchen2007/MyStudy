1. 首先注意到每个状态的下一状态唯一。
2. 总共的状态有2^8种，而N远远大于这个数字，所以根据容斥原理必定会出现循环。
3. 得到输入后先求一下第二天的状态，确保两端的cell为0，易于后面处理。

```
class Solution {
    const int n_cell=8;
    bool vis[256];
    int nxt[256];
    void make_nxt(){
        for(int i=0;i<(1<<n_cell);i++){
            int ret=0;
            for(int j=1;j<n_cell-1;j++){
                if((i>>j-1&1)^(i>>j+1&1)==false)
                    ret|=1<<j;
            }
            nxt[i]=ret;
        }
    }
    int get_status_from_vec(vector<int>& cells){
        int ret=0;
        for(int i=0;i<n_cell;i++)
            ret|=cells[i]<<i;
        return ret;
    }
    vector<int> status_into_vec(int status){
        vector<int> ret;
        for(int i=0;i<n_cell;i++)
            ret.push_back((status>>i)&1);
        return ret;
    }
    int get_circle_len(int s){
        int p=s;
        memset(vis,false,sizeof(vis));
        int len=0;
        while(vis[p]==false){
            len++;
            vis[p]=true;
            p=nxt[p];
        }
        return len;
    }
public:
    Solution(){
        make_nxt();
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int status=get_status_from_vec(cells);
        N--;
        status=nxt[status];
        int loop_len=get_circle_len(status);
        N%=loop_len;
        while(N--){
            status=nxt[status];
        }
        return status_into_vec(status);
    }
};
```
