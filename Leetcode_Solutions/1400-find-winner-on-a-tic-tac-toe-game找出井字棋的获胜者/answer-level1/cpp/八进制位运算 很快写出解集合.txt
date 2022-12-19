```cpp
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> winPattern{ 0007, 0070, 0700, 0111, 0222, 0444, 0124, 0421 };
        int A = 0;
        int B = 0;
        bool isA = true;
        for(int i =0;i<moves.size();++i){
            int pos = moves[i][0] * 3 + moves[i][1];
            if(isA){
                A |= 1 << pos;
                for(int& n : winPattern)
                    if((A & n) == n)
                        return "A";
            }
            else{
                B |= 1 << pos;
                for(int& n : winPattern)
                    if((B & n) == n)
                        return "B";
            }
            isA = !isA;
        }
        if(moves.size() == 9)
            return "Draw";
        else
            return "Pending";
    }
};
```
