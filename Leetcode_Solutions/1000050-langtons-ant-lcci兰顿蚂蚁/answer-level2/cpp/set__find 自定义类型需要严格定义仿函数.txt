### 解题思路


### 代码

```cpp
struct pt{
    int r;
    int c;
    pt(){}
    pt(int x, int y):r(x),c(y){}
    pt& operator=(const pt& rhs)
    {
        r = rhs.r;
        c = rhs.c;
        return *this;
    }
    bool operator<(const pt& rhs) const
    {
        return (this->r < rhs.r);
    }
};

class Solution {
public:
    vector<string> printKMoves(int K) {
        if(K==0) return {"R"};
        int left =0;
        int right =0;
        int up = 0;
        int down =0;
        vector<char> directions = {'L', 'U','R','D'};
        vector<int> hori = {-1, 0, 1, 0};
        vector<int> verti = {0, -1, 0, 1};
        int curr_direction = 2;
        set<pair<int,int>> blackSet;
        pt curr_pos(0,0);
        for(int i=0;i<K;i++)
        {
            if(blackSet.find(pair(curr_pos.r, curr_pos.c)) == blackSet.end()){
                blackSet.insert(pair(curr_pos.r,curr_pos.c));
                curr_direction = (curr_direction+1) % 4;
            }
            else{
                blackSet.erase(pair(curr_pos.r,curr_pos.c));
                curr_direction = (curr_direction+3) % 4;
            }
            curr_pos.r += verti[curr_direction];
            curr_pos.c += hori[curr_direction];
            left = min(left, curr_pos.c);
            right = max(right, curr_pos.c);
            up = min(up, curr_pos.r);
            down = max(down, curr_pos.r);
        }
        for(auto a:blackSet){
            cout<<a.first<<" "<<a.second<<endl;
        }
        int m = down - up+1;
        int n = right-left+1;
        vector<string> ans(m,string(n,'_'));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int r = i+up;
                int c = j+left;
                if(r==curr_pos.r && c == curr_pos.c){
                    ans[i][j]=directions[curr_direction];
                    continue;
                }
                if(blackSet.find(pair(r,c))==blackSet.end()){
                    ans[i][j]='_';
                }
                else {
                    ans[i][j]='X';
                }
            }
        }
        return ans;


    }
};
```