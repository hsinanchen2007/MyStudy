### 解题思路


### 代码

```cpp
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        int overlap_area = 0; //重叠部分面积

        if(!(E >= C || G <= A || F >= D || H <= B)) //必须先判断重叠
        {
            //找出重叠部分左下顶点 与 右上顶点坐标
            int x1 = max(A, E);
            int x2 = min(C, G);
            int y1 = max(B, F);
            int y2 = min(D, H);

            overlap_area = (x2 - x1) * (y2 - y1);
        }
        
        int area_1 = (C - A) * (D - B); //矩形1的面积
        
        int area_2 = (G - E) * (H - F);//矩形2的面积

        return area_1 + (area_2 - overlap_area); //防止溢出 先减后加
    }
};
```