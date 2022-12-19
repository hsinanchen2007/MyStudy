1. 题目本身不难，关键点在于set操作时，需要对涉及到的sum关系进行更新，这时需要递归才行。
```
class Excel {
public:
    vector<vector<int>> parse(string str){
        vector<vector<int>> res;
        int i = 0;
        
        while(i < str.size()){
            if(str[i] == ':'){
                ++i;
                continue;
            }
            
            /*parse*/
            vector<int> point;
            int r = 0;
            int c = 0;
            while(i < str.size() && str[i] >= 'A' && str[i] <= 'Z'){
                c = str[i] - 'A';
                ++i;
            }
            point.push_back(c);
            while(i < str.size() && str[i] >= '0' && str[i] <= '9'){
                r = r*10 + str[i] - '0';
                ++i;
            }
            point.push_back(r-1);
            reverse(point.begin(),point.end());
            res.push_back(point);
        }
        
        return res;
    }
    
    Excel(int H, char W) {
        this->row = H;
        this->colum = W-'A'+1;
        grid = vector<vector<int>>(H,vector<int>(W-'A'+1,0));
        father = vector<map<int,int>>(row*colum);
        child = vector<map<int,int>>(row*colum);
    }
    
    void flush(int r,char c){
        int key = (r-1)*colum + c - 'A';
        
        for(auto it : child[key]){
            father[it.first].erase(key);
        }
        child[key].clear();
    }
    
     bool dfs(int r,int c,int change){
         int key = r*colum + c;
         
         for(auto &it : father[key]){
             int x = it.first/colum;
             int y = it.first%colum;
             grid[x][y] += it.second*change;
             dfs(x,y,it.second*change);
         }
         
         return true;
     }
    
    void set(int r, char c, int v) {
        int change = v - grid[r-1][c-'A'];
        int key = (r-1)*colum + c - 'A';
        
        grid[r-1][c-'A'] = v;
        flush(r,c);
        
        /*update*/
        dfs(r-1,c-'A',change); 
    }
        
    int get(int r, char c) {
        return grid[r-1][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int curr = 0;
        int key = (r-1)*colum + (c-'A');
        
        /*erase*/
        flush(r,c);
        
        /*update*/
        for(int i = 0;i < strs.size(); ++i){
            vector<vector<int>> range = parse(strs[i]);
            if(range.size() == 1){
                int x = range[0][0];
                int y = range[0][1];
                curr += grid[x][y];
                father[x*colum+y][key]++;
                child[key][x*colum+y] = 1;
            }else if(range.size() == 2){
                for(int j = range[0][0]; j <= range[1][0]; ++j){
                    for(int k = range[0][1]; k <= range[1][1]; ++k){
                        curr += grid[j][k];
                        father[j*colum+k][key]++;
                        child[key][j*colum+k] = 1;
                    }
                }
            }            
        }
        
        grid[r-1][c-'A'] = curr; 
        return curr;
    }
private:
    int row;
    int colum;
    vector<vector<int>> grid;
    /*上层节点*/
    vector<map<int,int>> father;
    /*下层节点*/
    vector<map<int,int>> child;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 */
```