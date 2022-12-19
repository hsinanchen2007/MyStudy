### 解题思路
参照题解中nettee的那个投影法写

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    bool x_overlap = !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0]);
    bool y_overlap = !(rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
    return x_overlap && y_overlap;
}

作者：nettee
链接：https://leetcode-cn.com/problems/rectangle-overlap/solution/tu-jie-jiang-ju-xing-zhong-die-wen-ti-zhuan-hua-we/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    bool flag1=(rec2[0]>=rec1[2]||rec2[2]<=rec1[0])?0:1;
    bool flag2=(rec2[1]>=rec1[3]||rec2[3]<=rec1[1])?0:1;
    return flag1&&flag2;
}

```