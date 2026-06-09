### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret; 
        int h_s = 0;
        int h_e = matrix.size() -1;
        if(h_e < 0)return ret;
        int w_s = 0; 
        int w_e = matrix[0].size() -1;
        if(w_e < 0)return ret;

        int mode = 0;
        while(w_s <= w_e && h_s <= h_e)
        {
            switch(mode)
            {
                case 0:
                {
                    for(int i = w_s; i<= w_e ; i++)
                    {
                        ret.push_back(matrix[h_s][i]);
                    }
                    h_s ++;
                }
                break;
                case 1:
                {
                    for(int i = h_s; i<= h_e ; i++)
                    {
                        ret.push_back(matrix[i][w_e]);
                    }
                    w_e --;
                }
                break;
                case 2:
                {
                    for(int i = w_e; i>=w_s; i--)
                    {
                        ret.push_back(matrix[h_e][i]);
                    }
                    h_e --;
                }
                break;
                case 3:
                {
                    for(int i = h_e; i>=h_s; i--)
                    {
                        ret.push_back(matrix[i][w_s]);
                    }
                    w_s ++;
                }
                break;
            }
            mode = (mode+1)%4;
        }
        return ret;
    }
};
```