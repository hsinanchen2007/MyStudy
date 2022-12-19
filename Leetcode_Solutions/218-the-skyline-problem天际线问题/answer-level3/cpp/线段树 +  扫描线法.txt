```
//线段树节点
class Node{ 
public: 
    int l, r, cover, len; //左端点， 右端点， 是否覆盖， 线段长度（高度） 
    Node(){this -> l = 0; this -> r = 0;this -> cover = 0; this -> len = 0;}
};
//建筑物竖边
class Line{ 
public:
    int x, y1, y2, state;// x坐标， 竖线下方y坐标， 竖线上方y坐标， 建筑物左边线还是右边线
    Line(){this -> x =0; this -> y1 = 0; this -> y2 = 0; this -> state = 0;}
    Line(int x, int y1, int y2, int state) { this->x = x; this->y1 = y1; this->y2 = y2; this->state = state; } 
    bool operator<(Line oth) { return this->x < oth.x; }
};
class Solution {
private:
    vector<int> nodes; //建筑物高度（需要添加0）
    vector<Node> sgt; // 线段树
    vector<Line> lines; //建筑物竖边集合
    //构建线段树
    void buildTree(int left, int right, int k = 1) {
        sgt[k].l = nodes[left], sgt[k].r = nodes[right];
        if(right - left  <= 1) return;
        int medium = (left + right) >> 1;
        buildTree(left, medium, (k << 1));
        buildTree(medium, right, (k << 1 | 1));
    }
    //更新节点长度（高度）
    void update(int k) {
        if(sgt[k].cover) sgt[k].len = sgt[k].r - sgt[k].l;
        else sgt[k].len = sgt[(k << 1)].len + sgt[(k << 1 | 1)].len;
     }
     //调整线段树
     void modifyTree(int x, int y, int z, int k = 1) {
         int left = sgt[k].l, right = sgt[k].r;
         if(x <= left && right <= y) sgt[k].cover += z;
         else {
             if (x < sgt[(k << 1)].r) modifyTree(x, y, z , k << 1);
             if (y > sgt[(k << 1 | 1)].l) modifyTree(x, y, z, k << 1 | 1);
         } 
         update(k);
     }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty()) return {};
        int num = buildings.size();
        nodes.resize(num + 2); nodes[1] = 0;
        sgt.resize((num << 3) + 1);
        lines.resize((num << 1) + 1);
        for(int i = 1; i <= num; i++) {
            nodes[i + 1] = buildings[i - 1][2];
            lines[i] = Line(buildings[i - 1][0], 0, buildings[i - 1][2], 1), lines[num + i] = Line(buildings[i -1 ][1], 0, buildings[i-1][2], -1); 
        }
        std::sort(nodes.begin() + 1, nodes.end());
        std::sort(lines.begin() + 1, lines.end());
        buildTree(1, num + 1);
        vector<vector<int>> ans = { {-1, -1} };
        //依次扫描建筑物竖边
        for(int i =1; i <= (num << 1); i ++){
            int prelen = sgt[1].len;
            modifyTree(lines[i].y1, lines[i].y2, lines[i].state);
            //判读扫描的建筑物高度有无改变
            if(prelen != sgt[1].len) {
                if(lines[i].x != ans.back()[0]) ans.push_back({lines[i].x, sgt[1].len});
                else ans.back()[1] = sgt[1].len == 0? 0 : max(ans.back()[1], sgt[1].len);
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};
```
