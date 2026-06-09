```C++ []
typedef pair<int,int> pii;

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        set<pii> steps;
        int tu = 0;
        int tr = 0;
        
        for(int i = 0;i < command.size(); ++i){
            steps.insert(make_pair(tr,tu));
            if(command[i] == 'R'){
                tr++;
            }else{
                tu++;
            }
        }
        
        /*check we can reach to the obstacles*/
        for(int i = 0;i < obstacles.size(); ++i){
            int minStep = min(obstacles[i][0]/tr,obstacles[i][1]/tu);
            int r = obstacles[i][0] - minStep*tr;
            int u = obstacles[i][1] - minStep*tu;
            if(steps.count(make_pair(r,u))&&
               obstacles[i][0] <= x && 
               obstacles[i][1] <= y){
                return false;
            }
        }
        
        int minStep = min(x/tr,y/tu);
        int r = x - minStep*tr;
        int u = y - minStep*tu;
        if(steps.count(make_pair(r,u))){
            return true;
        }
        
        return false;
    }    
};
```
```python []
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:  
        steps = set()
        tu = 0
        tr = 0
        
        for i in range(len(command)):
            steps.add((tr,tu))
            if command[i] == 'R':
                tr += 1
            else:
                tu += 1
        
        for i in range(len(obstacles)):
            minStep = min(obstacles[i][0]//tr,obstacles[i][1]//tu)
            x1 = obstacles[i][0] - minStep*tr
            y1 = obstacles[i][1] - minStep*tu
            if (x1,y1) in steps:
                if obstacles[i][0] <= x and obstacles[i][1] <= y:
                    return False
        
        minStep = min(x//tr,y//tu)
        x1 = x - minStep*tr
        y1 = y - minStep*tu
        if (x1,y1) in steps:
            return True
        else:
            return False
```