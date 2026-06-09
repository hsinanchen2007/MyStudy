class Solution {
public:
    bool judgeCircle(string moves) {
    int step[4]={0};
    for(char i:moves)
        if(i=='U') step[0]++;
        else if(i=='D') step[1]++;
        else if(i=='L') step[2]++;
        else if(i=='R') step[3]++;
    return step[0]==step[1]&&step[2]==step[3];
    }
};