这道题目我也是醉了，写了半天，才写正确。。。
1. 关键的地方在于利用并查集进行感染区域合并。
```
class Solution {
public:
    int find(vector<int> &f,int x){
        while(f[x] != x){
            x = f[x];
        }
        return x;
    }
    
    bool uni(vector<int> &f,int x,int y){
        int x1 = find(f,x);
        int y1 = find(f,y);
        f[y1] = x1;
        return true;
    }
    
    /*find the max area */
    int spreaOfVirus(vector<int> & viru,vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        set<int> visit;
        int res = 0;
        
        for(auto v : viru){
            int x = v/c;
            int y = v%c;
            for(int i = 0;i < 4; ++i){
                int x1 = x + d[i][0];
                int y1 = y + d[i][1];
                if(x1 >= 0 && y1 >= 0 && x1 < r && y1 < c){
                    if(grid[x1][y1] == 0 && !visit.count(x1*c+y1)){
                        visit.insert(x1*c+y1);
                        res++;
                    }
                }
            }
        }        
        
        return res;
    }
    
    /*count the walls which will be added*/
    int wallOfVirus(vector<int> & viru,vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;
        
        for(auto v : viru){
            int x = v/c;
            int y = v%c;
            for(int i = 0;i < 4; ++i){
                int x1 = x + d[i][0];
                int y1 = y + d[i][1];
                if(x1 >= 0 && y1 >= 0 && x1 < r && y1 < c){
                    if(grid[x1][y1] == 0){
                        res++;
                    }
                }
            }
        }        
        return res;
    }
    
    /*remove the area of virus*/
    bool removeVirus(vector<int> & viru,vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        
        for(auto v : viru){
            int x = v/c;
            int y = v%c;
            grid[x][y] = -1;
        }
        
        return true;
    }
    
    /*erea will sprea one sheet, we merge the sprea virus area*/
    bool mergeVirus(vector<int> & f,map<int,vector<int>> & virus,vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        map<int,vector<int>> merge;
        
        /*we broaden one sheet of the virus*/
        for(auto v : virus){ 
            int key = v.first;
            int sz = v.second.size();
            set<int> visit;
            
            for(int i = 0;i < sz; ++i){
                visit.insert(v.second[i]);
            }
            
            for(int i = 0;i < sz; ++i){
                int x = v.second[i]/c;
                int y = v.second[i]%c;
                
                for(int j = 0;j < 4; ++j){
                    int x1 = d[j][0] + x;
                    int y1 = d[j][1] + y;
                    
                    if(x1 >= 0 && y1 >= 0 && x1 < r && y1 < c){
                        int target = x1*c + y1;                        
                        if(grid[x1][y1] == 0 && visit.count(target) == 0){
                            visit.insert(target);
                            grid[x1][y1] = 1;
                            for(int k = 0; k < 4; ++k){
                                int x2 = d[k][0] + x1;
                                int y2 = d[k][1] + y1;
                                if(x2 >= 0 && y2 >= 0 && x2 < r && y2 < c && grid[x2][y2] == 1){
                                    uni(f,key,x2*c+y2);
                                }
                            }
                            uni(f,key,target);
                            virus[key].push_back(target);
                        }else if(grid[x1][y1] == 1 && visit.count(target) == 0){
                            visit.insert(target);
                            uni(f,key,target);
                        }
                    } 
                }
            }            
        }
        
        /*we find the merge virus*/
        for(auto v : virus){
            if(find(f,v.first) != v.first){
                merge[find(f,v.first)].push_back(v.first);
            }
        }
        
        /*we merge the virus*/
        for(auto m : merge){
            for(auto v : m.second){
                virus[m.first].insert(virus[m.first].begin(),virus[v].begin(),virus[v].end());
                virus.erase(v);
            }
        }
        
        return true;
    }
    
    bool debug(vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        return true;
    }
    
    int containVirus(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res = 0;
        vector<vector<bool>> visit(r,vector<bool>(c,false));
        map<int,vector<int>> virus;
        int d[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,int>> qu;
        vector<int> f(r*c+1,0);
        
        /*intial*/
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                f[i*c+j] = i*c+j;
            }
        }
        /*traverse*/
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(!visit[i][j] && grid[i][j] == 1){
                    qu.push(make_pair(i,j));
                    visit[i][j] = true;
                    virus[i*c+j].push_back(i*c+j);
                    
                    while(!qu.empty()){
                        pair<int,int> curr = qu.front();
                        qu.pop();
                        int x = curr.first;
                        int y = curr.second;
                        
                        for(int k = 0;k < 4; ++k){
                            int x1 = x + d[k][0];
                            int y1 = y + d[k][1];
                            
                            if(x1 >= 0 && x1 < r && y1 >= 0 && y1 < c){
                                if(!visit[x1][y1]&&grid[x1][y1] == 1){
                                    visit[x1][y1] = true;
                                    qu.push(make_pair(x1,y1));
                                    virus[i*c+j].push_back(x1*c+y1);
                                    f[x1*c+y1] = i*c+j;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        cout<<"sz = "<<virus.size()<<endl;
       
        while(virus.size() != 0){
            int maxSpea = 0;
            int idx = 0;
            
            /*we get the max spreaed area*/
            for(auto v: virus){
                int spea = spreaOfVirus(v.second,grid);
                if(spea > maxSpea){
                    idx = v.first;
                    maxSpea = spea;
                }
            }
            if(maxSpea == 0){ 
                break;
            }    
            
            /*we add all of the walls*/
            res += wallOfVirus(virus[idx],grid);
            /*we set walls of the max virus*/
            removeVirus(virus[idx],grid);
            /*we remove the max virus*/
            virus.erase(idx);
            /*we expect the next day and merge*/
            mergeVirus(f,virus,grid);
            //debug(grid);
        }
            
        return res;
    }
};
```