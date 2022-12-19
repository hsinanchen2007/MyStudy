class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int flag[numCourses];
        int has_hit[numCourses];
        vector<int> v;
        
        for(int i = 0; i < numCourses; i++){
            flag[i] = 0;
            has_hit[i] = 0;
        }

        map<int, vector<int>> m;
        for(int i = 0; i < prerequisites.size();  i++){
            vector<int> item = prerequisites[i];
            m[item[0]].push_back(item[1]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(m.count(i) == 0)
                flag[i] = 1;
        }
        
        int hit_num = 0;
        int last_hit_num = 0;
        while(hit_num < numCourses){
            
            for(int i = 0; i < numCourses; i++){
                if(flag[i] == 1 && has_hit[i] == 0){
                    has_hit[i] = 1;
                    v.push_back(i);
                    hit_num++;
                }
            }

            for(int i = 0; i < numCourses; i++){
                if(flag[i] != 0) continue;
                int key = i;
                vector<int> val = m[key];
                flag[i] = 1;
                for(int i = 0; i < val.size(); i++){
                    if(flag[val[i]] == 0){
                        flag[key] = 0;
                        break;
                    }
                }                
            }
            
            if(hit_num == last_hit_num){
                vector<int> tv;
                return tv;
            }
            last_hit_num = hit_num;
        }
        
        return v;
    }
    
};