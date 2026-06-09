### 解题思路
思路就是：
找到各种重叠情况？？？
头铁就完事了，回去赶紧补一个4行的代码
### 代码

```cpp
/*
*四个顶点必在另一个矩形中
后来发现不是的，还有两种情况，十字架 和 平移 顶点都不在另一个正方形中，
*/
/*
*矩形以列表 [x1, y1, x2, y2] 的形式表示，
*其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)

    {
        /*while(rec1.size()!=4||rec2.size()!=4)
            return false;
        */
        if (rec1 == rec2)
        {
            return true;
        }

        vector<vector<int>> posi = {{0, 1}, {0, 3}, {2, 1}, {2, 3}}; //四个顶点位置 左下，左上，右下，右上

        for (auto angle : posi)
        {
            if (rec1[angle[0]] < rec2[2] && rec1[angle[0]] > rec2[0] && rec1[angle[1]] > rec2[1] && rec1[angle[1]] < rec2[3])
            {
                return true;
            }
        }
        //不包括部分边重合的重叠，
        if (rec1[0] == rec2[0] && rec1[2] == rec2[2] && (rec1[1] < rec2[3] && rec1[1] > rec2[1] || rec1[3] < rec2[3] && rec1[3] > rec2[1])) //判断x重合 横着平移
        {
            return true;
        }
        if (rec1[1] == rec2[1] && rec1[3] == rec2[3] && (rec1[0] < rec2[2] && rec1[0] > rec2[0] || rec1[2] < rec2[2] && rec1[2] > rec2[0])) //判断y重合 竖着平移
        {
            return true;
        }
        //十字架
        if(rec1[0]<=rec2[0]&&rec1[2]>=rec2[2] && rec2[1]<=rec1[1]&&rec2[3]>=rec1[3]){//rec1包rec2 的x ，rec2包rec1的y ，定点都在外部，
            return true;
        }

        //交换两个矩形
        vector<int> tmp = rec1;
        rec1 = rec2;
        rec2 = tmp;

        //角在内部
        for (auto angle : posi)
        {
            if (rec1[angle[0]] < rec2[2] && rec1[angle[0]] > rec2[0] && rec1[angle[1]] > rec2[1] && rec1[angle[1]] < rec2[3])
            {
                return true;
            }
        }
        //两条边重合，平移
        if (rec1[0] == rec2[0] && rec1[2] == rec2[2] && (rec1[1] < rec2[3] && rec1[1] > rec2[1] || rec1[3] < rec2[3] && rec1[3] > rec2[1])) //判断x重合 横着平移
        {
            return true;
        }
        if (rec1[1] == rec2[1] && rec1[3] == rec2[3] && (rec1[0] < rec2[2] && rec1[0] > rec2[0] || rec1[2] < rec2[2] && rec1[2] > rec2[0])) //判断y重合 竖着平移
        {
            return true;
        }
        //十字架
        if(rec1[0]<=rec2[0]&&rec1[2]>=rec2[2] && rec2[1]<=rec1[1]&&rec2[3]>=rec1[3]){//rec1包rec2 的x ，rec2包rec1的y ，定点都在外部，
            return true;
        }

        return false;
        // while (rec1[0] < rec2[3] && rec1[0] || || ||)
    }
};

```