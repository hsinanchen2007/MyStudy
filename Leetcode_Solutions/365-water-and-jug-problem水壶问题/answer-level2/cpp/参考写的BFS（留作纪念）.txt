```
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0 || x==z || y==z || x+y==z){
            return true;
        }
        if(z<0 || x+y < z){
            return false;
        }

        queue<pair<int, int>> queueState;
        queueState.push(make_pair(0, 0));
        set<pair<int, int>> visited;
        visited.insert(make_pair(0, 0));

        while (!queueState.empty()){
            pair<int, int> currentState = queueState.front();
            queueState.pop();
            if (currentState.first == z || currentState.second == z || currentState.first+currentState.second == z){
                return true;
            }
            if(currentState.first == 0 && visited.count(make_pair(x, currentState.second))==0){
                visited.insert(make_pair(x, currentState.second));
                queueState.push(make_pair(x, currentState.second));
            }
            if(currentState.second == 0 && visited.count(make_pair(currentState.first, y))==0){
                visited.insert(make_pair(currentState.first, y));
                queueState.push(make_pair(currentState.first, y));
            }
            if(currentState.second < y && visited.count(make_pair(0, currentState.second))==0){
                visited.insert(make_pair(0, currentState.second));
                queueState.push(make_pair(0, currentState.second));
            }
            if(currentState.first < x && visited.count(make_pair(currentState.first, 0))==0){
                visited.insert(make_pair(currentState.first, 0));
                queueState.push(make_pair(currentState.first, 0));
            }

            int move = min(currentState.first, y-currentState.second);
            if (visited.count(make_pair(currentState.first-move, currentState.second+move))==0){
                visited.insert(make_pair(currentState.first-move, currentState.second+move));
                queueState.push(make_pair(currentState.first-move, currentState.second+move));
            }

            move = min(x - currentState.first, currentState.second);
            if (visited.count(make_pair(currentState.first+move, currentState.second-move))==0){
                visited.insert(make_pair(currentState.first+move, currentState.second-move));
                queueState.push(make_pair(currentState.first+move, currentState.second-move));
            }
        }
        return false;
    }
};
```
