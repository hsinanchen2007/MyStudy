求两个面积和减去重叠部分的
！！注意不能先求和，要先减，负责会超出int范围
![image.png](https://pic.leetcode-cn.com/a79912b2f4f096731969ce4b57b165ff2a970137eb3a8da6292673ce36cc53ea-image.png)
```
bool check(pair<int,int>temp1,pair<int,int>temp2){
    if(temp1>temp2)
        return temp1.first>=temp2.second? false: true;
    else
        return temp2.first>=temp1.second? false: true;
}
int Value(pair<int,int>temp1,pair<int,int>temp2){
    if(check(temp1,temp2)){
        if(temp1>temp2)
            return temp1.second < temp2.second?temp1.second - temp1.first:temp2.second - temp1.first;
        else
            return temp2.second < temp1.second?temp2.second - temp2.first:temp1.second - temp2.first;
    } else
        return 0;

}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    pair<int,int>rec1_x(A,C);
    pair<int,int>rec1_y(B,D);
    pair<int,int>rec2_x(E,G);
    pair<int,int>rec2_y(F,H);
    return (C-A)*(D-B)-Value(rec1_x,rec2_x)*Value(rec1_y,rec2_y)+(G-E)*(H-F);
}
```

