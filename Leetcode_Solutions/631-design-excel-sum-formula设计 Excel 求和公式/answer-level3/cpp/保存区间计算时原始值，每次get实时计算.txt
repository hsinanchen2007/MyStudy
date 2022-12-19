```
class Excel {
public:
    Excel(int H, char W) {
        grid = vector<vector<int>>(H+1, vector<int>(W-'A'+1, 0));
        number = vector<vector<vector<string>>>(H+1, vector<vector<string>>(W-'A'+1));
    }
    
    void set(int r, char c, int v) {
        grid[r][c-'A'] = v;
        number[r][c-'A'].clear();
    }
    
    int get(int r, char c) {
        if(number[r][c-'A'].empty()) return grid[r][c-'A'];
        return calculate(number[r][c-'A']);
    }

    int calculate(vector<string>& strs) {
        int res = 0;
        for(string str: strs) {
            res += calculate(str);
        }
        return res;
    }
    int calculate(string& s) {
        if(s.size()==2) {
            return get(s[1]-'0', s[0]);
        }
        // 解析起始点和终点
        char cl, cr;
        int rl=0, rr=0, res=0, n=s.size(), i=0;
        cl = s[i++];
        while(s[i]!=':') rl = rl*10 + s[i++]-'0';
        i++;
        cr = s[i++];
        while(i<n) rr = rr*10 + s[i++]-'0';
        for(char c=cl; c<=cr;c++) {
            for(int x=rl; x<=rr; x++) {
                res += get(x, c);
            }
        }
        // cout<<s<<res<<endl;
        return res;
    }
    
    int sum(int r, char c, vector<string> strs) {
        number[r][c-'A'] = move(strs);
        return get(r, c);
    }
private:
    vector<vector<int>> grid;
    vector<vector<vector<string>>> number;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 */
```
