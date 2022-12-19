超级简单，算出任意两个点之间距离，排序，只要第0个和第3个大小一样且不为0集可
超过C++ 100%。
@18861515833 感谢提出的问题，正方形是四边相等且对角线相等；菱形是四边相等；
测试样例不够严谨呀！！！

```
class Solution {
public:
    int dist(vector<int> a, vector<int> b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> temp;
        temp.push_back(dist(p1, p2));
        temp.push_back(dist(p1, p3));
        temp.push_back(dist(p1, p4));
        temp.push_back(dist(p2, p3));
        temp.push_back(dist(p2, p4));
        temp.push_back(dist(p3, p4));
        sort(temp.begin(), temp.end());
        return (temp[0] == temp[3]) && temp[4] == temp[5] && temp[0] != 0 ;
    }
};
```
