### 解题思路
此处撰写解题思路
傻瓜排除法，先删掉肯定不是的绝大多数，只有行和列均为1才可能是孤独点，但不一定是B。最后再返回去看一下哪些是B，返回这些即可。
### 代码

```cpp
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int> raw(m,0);
        vector<int> column(n,0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(picture[i][j] == 'B'){
                    raw[i] += 1;
                    column[j] += 1;
                }
            }
        }
        int raw_num = 0;
        for(int j = 0, f = 0; j < m; j++){
            if(raw[j] == 1){
                raw[f] = j;
                f++;
                raw_num++;
            }
        }
        int column_num = 0;
        for(int j = 0, f = 0; j < n; j++){
            if(column[j] == 1){
                column[f] = j;
                f++;
                column_num++;
            }
        }
        int all_B = 0;
        for(int j = 0; j < raw_num; j++){
            for(int i = 0; i < column_num; i++){
                if(picture[raw[j]][column[i]] == 'B'){
                    all_B++;
                }
            }
        }
        return all_B;
    }
};
```