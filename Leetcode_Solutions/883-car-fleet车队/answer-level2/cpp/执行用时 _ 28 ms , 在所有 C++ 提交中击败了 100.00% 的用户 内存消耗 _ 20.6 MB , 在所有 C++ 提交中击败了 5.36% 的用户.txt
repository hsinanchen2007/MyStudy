```
struct CarStruct{
    int pos;
    float time;
};

static bool compare(CarStruct &v1,CarStruct &v2){
    if(v1.pos<v2.pos){
        return true;
    }
    else if(v1.pos==v2.pos&&v1.time<v2.time){
        return true;
    }
    return false;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==0){
            return 0;
        }
        vector<CarStruct> carVect(position.size());
        for(int i=0;i<position.size();i++){
            carVect[i].pos = target - position[i];
            carVect[i].time = (float)carVect[i].pos/(float)speed[i];
        }
        int group =1;
        sort(carVect.begin(),carVect.end(),compare);
        for(int i=1;i<carVect.size();i++){
            if(carVect[i].time>carVect[i-1].time){
                group++;
            }
            else {
                carVect[i].time = carVect[i-1].time;
            }
        }
        return group;
    }
};
```
