先排序，再枚举矩形左下和右上两个点，二分查找剩余两个点是否存在。
```
class Solution {
public:
    struct node {
        int x,y;
        friend bool operator<(const node &a, const node &b){
            if (a.x < b.x) return true;
            if (a.x > b.x) return false;
            if (a.y < b.y) return true;
            return false;
        }
    }d[501];
    bool check(int l, int r, int x, int y)
    {
        if (r-l<=1) {
            if (d[l].x == x && d[l].y == y) {
                return true;
            }
            if (d[r].x == x && d[r].y == y) {
                return true;
            }
            return false;
        }
        int mid = (l+r)>>1;
        if (x<d[mid].x||(x==d[mid].x&&y<=d[mid].y)){
            return check(l,mid,x,y);
        }else {
            return check(mid+1,r,x,y);
        }
    }
    int minAreaRect(vector<vector<int>>& points) {
        int answer = 1600000000;
        int len = points.size();
        for (int i=0; i<len;i++){
            d[i+1].x = points[i][0];
            d[i+1].y = points[i][1];
        }
        sort(d+1, d+len+1);
        for (int i=1; i<len ;i++){
            for (int j=i+1; j<=len; j++) {
                if (d[i].x==d[j].x || d[i].y==d[j].y){
                    continue;
                }
                if (((d[j].y-d[i].y)*(d[j].x-d[i].x))>=answer){
                    continue;
                }
                if (check(i,j,d[i].x,d[j].y)&&check(i,j,d[j].x,d[i].y)) {
                    answer = (d[j].y-d[i].y)*(d[j].x-d[i].x);
                }
            }
        }
        return answer == 1600000000 ? 0:answer;
    }
};
```
![E51F7895-3A98-4803-9486-C75991EAEB2C.png](https://pic.leetcode-cn.com/87c58305aa91da3a3b9a58da0a5afd9000d24d9cd0690032a1c15b3f9a526362-E51F7895-3A98-4803-9486-C75991EAEB2C.png)


