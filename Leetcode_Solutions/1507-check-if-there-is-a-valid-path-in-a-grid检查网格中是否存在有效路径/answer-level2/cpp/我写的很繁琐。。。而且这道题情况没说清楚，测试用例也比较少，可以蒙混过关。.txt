### 解题思路
![413422BB-4064-4835-A27E-C8ED5402A7F3.png](https://pic.leetcode-cn.com/293559cf0b75bcc21ca649d96bf5000fd2db6cba8c5236900d03d5fd93bb9244-413422BB-4064-4835-A27E-C8ED5402A7F3.png)


此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = 0;
        if(i+1 == m && j+1 == n)
            return true;
        int temp_dir = 0;//上：0，下：1，左：2，右：3
        if(grid[0][0] == 1 || grid[0][0] == 6){
            temp_dir = 3;
            j = j+1;
            if(j > n-1 || j < 0)
                return false;
        }
        else if(grid[0][0] == 2 || grid[0][0] == 3){
            temp_dir = 1;
            i = i+1;
            if(i > m-1 || i < 0)
                return false;
        }
        else if(grid[0][0] == 5){
            return false;
        }
        else{
            temp_dir = 1;
            i = i+1;
            if(i > m-1 || i < 0)
                return false;
        }
        while(1){
            if(temp_dir == 0){
                if(grid[i][j] == 2||grid[i][j] == 3|| grid[i][j] == 4){
                    if(i == m-1 && j == n-1){
                        return true;
                    }
                    if(grid[i][j] == 2){
                        i = i-1;
                        if(i > m-1 || i < 0)
                            return false;
                        else{
                            temp_dir = 0;
                            continue;
                        }
                    }
                    else if(grid[i][j] == 3){
                        j = j-1;
                        if(j > n-1 || j < 0)
                            return false;
                        else{
                            temp_dir = 2;
                            continue;
                        }
                    }
                    else{
                        j = j+1;
                        if(j > n-1 || j < 0)
                            return false;
                        else{
                            temp_dir = 3;
                            continue;
                        }
                    }
                }
                else{
                    return false;
                }
            }
            else if(temp_dir == 1){
                if(grid[i][j] == 2||grid[i][j] == 5|| grid[i][j] == 6){
                    if(i == m-1 && j == n-1){
                        return true;
                    }
                    if(grid[i][j] == 2){
                        i = i+1;
                        if(i > m-1 || i < 0)
                            return false;
                        else{
                            temp_dir = 1;
                            continue;
                        }
                    }
                    else if(grid[i][j] == 5){
                        j = j-1;
                        if(j > n-1 || j < 0)
                            return false;
                        else{
                            temp_dir = 2;
                            continue;
                        }
                    }
                    else{
                        j = j+1;
                        if(j > n-1 || j < 0)
                            return false;
                        else{
                            temp_dir = 3;
                            continue;
                        }
                    }
                }
                else{
                    return false;
                }
            }
            else if(temp_dir == 2){
                if(grid[i][j] == 1||grid[i][j] == 4|| grid[i][j] == 6){
                    if(i == m-1 && j == n-1){
                        return true;
                    }
                    if(grid[i][j] == 4){
                        i = i+1;
                        if(i > m-1 || i < 0)
                            return false;
                        else{
                            temp_dir = 1;
                            continue;
                        }
                    }
                    else if(grid[i][j] == 1){
                        j = j-1;
                        if(j > n-1 || j < 0)
                            return false;
                        else{
                            temp_dir = 2;
                            continue;
                        }
                    }
                    else{
                        i = i+1;
                        if(i > m-1 || i < 0)
                            return false;
                        else{
                            temp_dir = 0;
                            continue;
                        }
                    }
                }
                else{
                    return false;
                }
            }
            else{
                if(grid[i][j] == 1||grid[i][j] == 3|| grid[i][j] == 5){
                    if(i == m-1 && j == n-1){
                        return true;
                    }
                    if(grid[i][j] == 3){
                        i = i+1;
                        if(i > m-1 || i < 0)
                            return false;
                        else{
                            temp_dir = 1;
                            continue;
                        }
                    }
                    else if(grid[i][j] == 1){
                        j = j+1;
                        if(j > n-1 || j < 0)
                            return false;
                        else{
                            temp_dir = 3;
                            continue;
                        }
                    }
                    else{
                        i = i-1;
                        if(i > m-1 || i < 0)
                            return false;
                        else{
                            temp_dir = 0;
                            continue;
                        }
                    }
                }
                else{
                    return false;
                }
            }
        }
    }
};
```