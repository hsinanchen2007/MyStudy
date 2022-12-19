![WX20200311-123143@2x.png](https://pic.leetcode-cn.com/20f8087237ac2471359c5c43ab59645f252a41c188e65bf3376aea5ac98a8f67-WX20200311-123143@2x.png)

刚从计算矩阵面积那里出来的，做题还是很忌讳一拿到题目就扎进去
一开始想的是，先把两个矩形的各种组合形式画出来，很麻烦
后来一想，如果只判断x轴方向上的两个区间段是否重叠，那不就成了合并区间。
所以这道题目便转化成了，x和y上的区间有没有重叠。
pair比较大小的时候会自动实现小在前，短在前这一特点
![image.png](https://pic.leetcode-cn.com/62f00ee17f93e08e09e97d8186fbd91d1dc625d4fa6e45ddb1ebee52b85529b1-image.png)
***！！注意有为什么是 >= 呢？，因为[1,2],[2,3]也是不重叠的***
```
bool check(pair<int,int>temp1,pair<int,int>temp2){
    if(temp1>temp2)
        return temp1.first>=temp2.second? false: true;
    else
        return temp2.first>=temp1.second? false: true;
}
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    pair<int,int>helper1_x{rec1[0],rec1[2]};
    pair<int,int>helper1_y{rec1[1],rec1[3]};

    pair<int,int>helper2_x{rec2[0],rec2[2]};
    pair<int,int>helper2_y{rec2[1],rec2[3]};
    return check(helper1_x,helper2_x)&&check(helper1_y,helper2_y);
}
```


