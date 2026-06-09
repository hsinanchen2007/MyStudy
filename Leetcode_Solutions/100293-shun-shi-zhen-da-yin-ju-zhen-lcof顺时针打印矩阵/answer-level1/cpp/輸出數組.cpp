### 解题思路
詳細見代碼。注意的是每次切換方向時，當前位置的數不能重複輸出，以及儅行列不相等時某一方剩餘處理數目為零則先處理另一個方向然後再終止循環，結束放置。
以及向下使用的是i++，數組列出的從上之下和計算機數組結構是不同的（1-n，n越大越靠下）。



### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0) return ans;
        int h=matrix.size()-1,w=matrix[0].size();//h減少1因爲第一次的時候第一個在向右遍歷時已經遍歷過了
        int x=0,y=0;
        bool right=true,down=true;
        ans.push_back(matrix[0][0]);
        while(h||w)
        {
                if(right&&w)
                {
                    int i;
                    if(w==matrix[0].size())  i=1;//第一次情況特殊處理
                    else  i=0;
                    for(;i<w;i++)
                        ans.push_back(matrix[y][++x]);
                    right=false;
                    w--;
                }else if(!right&&w){//向左
                
                   for(int i=0;i<w;i++){//記錄應該遞減的次數
                    ans.push_back(matrix[y][--x]);
                    } 
                    right=true;
                    w--;
                }
                if(h==0) break;  
                if(down&&h)
                {
                    for(int i=0;i<h;i++){
                        ans.push_back(matrix[++y][x]) ;//down的時候是加
                    }
                    down=false;
                    h--;
                }else if(!down&&h){
                    for(int i=0;i<h;i++) 
                        ans.push_back(matrix[--y][x]);
                    down=true;
                    h--;
                }
                if(w==0) break;                               
        }
        return ans;
    }
};
```