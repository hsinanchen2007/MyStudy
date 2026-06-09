### 解题思路
想想一下你在开车，碰到指示牌就转向...你遇到指示牌后必须调整该指示牌的下一个位置。
还需注意：当列数大于行数的时候，可能会遇到错误的转向，比如3*5的矩阵，在1，1位置会错误转上。
因而采用pair数组来记录上一次方向和当前方向。
over!
![1.png](https://pic.leetcode-cn.com/a2899b6535211314ef956cb549104799c8f3c00a9ebf1643d99165067e2b2b6a-1.png)


### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()<1) return result;

        int m = matrix.size();//行数
        int n = matrix[0].size();//列数

        // 四块指示牌
        pair<int,int> right(1,0);
        pair<int,int> down(0,n-1);
        pair<int,int> left(m-1,n-1);
        pair<int,int> up(m-1,0);
        pair<int,int> velocity(0,1);//速度
        enum flag{_Left,_Right,_Up,_Down,_Ini};

        pair<int,int> coor(0,0);//当前坐标
        pair<flag,flag> last_flag(_Up,_Right);//上一状态和当前状态
        for(int i=0;i<m*n;i++){
            int ele = matrix[coor.first][coor.second];
            result.push_back(ele);
            // 遇到拐点响应的改变速度，否则不变
            if(coor==down && last_flag.second==_Right){
                velocity= make_pair(1,0);
                down.first = coor.first+1;
                down.second = coor.second-1;
                last_flag.first=last_flag.second;
                last_flag.second= _Down;
            }else if(coor==left && last_flag.second==_Down){
                velocity= make_pair(0,-1);
                left.first = coor.first-1;
                left.second = coor.second-1;
                last_flag.first=last_flag.second;
                last_flag.second= _Left;
            }else if(coor==up && last_flag.second==_Left){
                velocity= make_pair(-1,0);
                up.first = coor.first-1;
                up.second = coor.second+1;
                last_flag.first=last_flag.second;
                last_flag.second= _Up;
            }else if( coor==right && last_flag.second==_Up){
                velocity= make_pair(0,1);
                right.first = coor.first+1;
                right.second = coor.second+1;
                last_flag.first=last_flag.second;
                last_flag.second= _Right;
            }

            coor.first += velocity.first;
            coor.second += velocity.second;
        }

        return result;
    }
};
```