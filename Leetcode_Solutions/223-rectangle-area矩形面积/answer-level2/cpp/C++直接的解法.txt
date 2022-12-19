上来直接计算重叠区域，判断能不能构成重叠。然后分别采取对应的措施。最气的题目说了“重叠后”，居然和有算例不重叠，误导人啊。

这题不需要做过多的讨论，就这么几种情况：
1.两个矩形分离
2.两个矩形嵌套
3.两个矩形重叠
```
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //分别计算两个矩形的面积
        long long Area1=((long long)C-A)*((long long)D-B);
        long long Area2=((long long)G-E)*((long long)H-F);
        //计算重合区域
        long long x1=0,y1=0,x2=0,y2=0;
        x1=max(A,E);
        y1=max(B,F);
        x2=min(C,G);
        y2=min(D,H);

        long long x3=x2-x1;
        long long y3=y2-y1;

        if(x3<=0 || y3<=0)  //不重合
            return (Area1+Area2);
        int ans=0;
        //计算重合区域的面积,原则上重合区域的面积应该比较两个矩形都小
        long long Area3=(x2-x1)*(y2-y1);
        if(Area3==Area1)       //如果和其中一个相同，则这个小矩形被嵌套在大矩形中
            ans=Area2;
        if(Area3==Area2)
            ans=Area1;
        if(Area3<Area1 && Area3<Area2)  //没有嵌套
            ans=Area1+Area2-Area3;
        return ans;
    }
```


