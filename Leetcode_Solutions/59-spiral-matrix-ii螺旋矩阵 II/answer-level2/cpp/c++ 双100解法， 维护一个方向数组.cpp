### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<bool> tmp_saver(n, false);
    vector<vector<bool>> masks(n, tmp_saver);
        vector<int> tmp(n, 0);
    vector<vector<int>> res(n, tmp);
    int counter = 1;
    int x =0, y =0;
    vector<int> direct1{0, 1}, direct2{1, 0}, direct3{0, -1}, direct4{-1, 0};
    vector<vector<int>> direct{direct1, direct2, direct3, direct4};
    vector<int> now_direct = direct1;
    int now_direct_index = 0;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            int new_x, new_y;

            if(masks[x][y] == false){
                res[x][y] = counter;
                masks[x][y] = true;
            }

            new_x = x+now_direct[0];
            new_y = y+now_direct[1];

            if(new_x<0||new_y<0 || new_x>=n|| new_y>=n||masks[new_x][new_y]== true ){

                if(now_direct_index<3)
                    now_direct_index++;
                else
                    now_direct_index = 0;
                now_direct = direct[now_direct_index];
            }
            x = x+now_direct[0];
            y = y+now_direct[1];
            counter++;

        }
    }
    return  res;

    }
};
```