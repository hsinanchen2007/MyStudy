![image.png](https://pic.leetcode-cn.com/b4185793ee46c6cb8c99e33e0f1ef1b63be9771a6bc3e081a3d3ffb73094f81b-image.png)

```
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        string arr[3][3] = {""}, res = "Pending";
        for(int i=0;i<moves.size();i++)
        {
            arr[moves[i][0]][moves[i][1]] = (i % 2 == 0 ? "X" : "O");
        }
        if( (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][2] == "X") ||
            (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][2] == "X") ||
            (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2] == "X") ||
            (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[2][0] == "X") ||
            (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1] == "X") ||
            (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[2][2] == "X") ||
            (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == "X") ||
            (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[0][2] == "X") )
        {
            res = "A";
        }
        else if((arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][2] == "O") ||
                (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][2] == "O") ||
                (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2] == "O") ||
                (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[2][0] == "O") ||
                (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1] == "O") ||
                (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[2][2] == "O") ||
                (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == "O") ||
                (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[0][2] == "O"))
        {
            res = "B";
        }
        else if(moves.size() == 9)
        {
            res = "Draw";
        }
        return res;
    }
};
```

