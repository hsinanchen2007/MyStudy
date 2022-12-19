利用点积和叉积的性质来判断。
点积为a * b * cos(/theta)
叉积的模为a和b向量组成的平行四边形的面积
1. 判断从一个点出发的三个向量的两两相乘有一个点积为零
2. 判断三个叉积的绝对值是否两两相等
3. 叉积绝对值乘以2是否等于点积和

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //点积和叉积
        int tmpX12 = p2[0] - p1[0];
        int tmpX13 = p3[0] - p1[0];
        int tmpX14 = p4[0] - p1[0];
        int tmpY12 = p2[1] - p1[1];
        int tmpY13 = p3[1] - p1[1];
        int tmpY14 = p4[1] - p1[1];
        int dP123 = tmpX12 * tmpX13 + tmpY12 * tmpY13;
        int dP124 = tmpX12 * tmpX14 + tmpY12 * tmpY14;
        int dP134 = tmpX13 * tmpX14 + tmpY13 * tmpY14;
        int cP123 = abs(tmpX12 * tmpY13 - tmpX13 * tmpY12);
        int cP124 = abs(tmpX12 * tmpY14 - tmpX14 * tmpY12);
        int cP134 = abs(tmpX13 * tmpY14 - tmpX14 * tmpY13);   
        int tmp = 0;
        tmp += (dP123 == 0 ? 0 : 1);
        tmp += (dP124 == 0 ? 0 : 1);
        tmp += (dP134 == 0 ? 0 : 1);
        if (tmp != 2) return false;
        if (cP123 != cP124 || cP123 != cP134 || cP124 != cP134) return false;
        if ((dP123 + dP124 + dP134) != (cP124 << 1)) return false;
        return true;
    }
};

