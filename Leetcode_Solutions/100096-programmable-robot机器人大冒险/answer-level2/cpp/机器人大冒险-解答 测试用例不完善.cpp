输入的规模：2 <= command的长度 <= 1000
command由U，R构成，且至少有一个U，至少有一个R
0 <= x <= 1e9, 0 <= y <= 1e9
0 <= obstacles的长度 <= 1000
 
从输入规模可以看出，地图的大小很大。但是实际上的每一轮循环路程最多也就只移动了1000步。同时障碍物的个数也不超过1000个
所以用一张最大不超过1000\*1000的地图完全可以描述出所有情况。
地图的实际大小由：
	height：操作U的总和
	width：操作R的总和     
共同来决定
由于只能向右走和向上走，如下图，可能走到的区域呈现楼梯式分布
![fullsizerender.jpg](https://pic.leetcode-cn.com/099198d4c1e65c82885fc6b40ce14816a1241b83dd5663d7c2ea3ab92039bdb1-fullsizerender.jpg)
每个矩形代表着一次循环。
所以我们需要做的工作就是把所有的障碍物点进行条件筛选后经过坐标转换添加到大小为height\*wide的地图中去。
筛选障碍物的条件为：障碍物必须处于阶梯的区域内并且坐标小于终点的坐标
显而易见若障碍物处于阶梯形区域之外必然不可能碰撞到，处于终点之后的障碍物也不会发生碰撞，因此不必添加。
添加完障碍物后相当于把所有障碍物压缩到了一张更小的图上
障碍物的存储可以通过一个二维数组或者Hash表实现，由于坐标值不可能大于1000
简便起见可以设key值为x\*10000+y
然后只需要经过一轮的循环就能判断出有没有障碍物碰撞到。
同理是否可以到达终点也可以通过坐标转换来实现。
时间复杂度为O（n+m）n为命令长度，m为障碍物的数量
空间复杂度为：
二维数组存储：O（height × width）开辟一个等面积的数组
Hash表存储：O（m）最坏情况需要开辟一个大小等同于障碍物数量的Hash表

PS：在进行坐标转换时需要注意一种正好处于两个区域分界的那条边上时，需要判断是处于上面的区域还是下面的区域。
如指令为"RRRUUU"
障碍物为（3，1）（3，2），此时障碍物正好处于边的右边界。
测试用例中没有考虑到这种情况，该例子下明显会在（3，1）与（3，2）发生碰撞，但是测试的时候竟然预期结果竟然为True。。。


具体实现代码如下
```

class Solution {
private:
int wide=0;
int high=0;
public:
    void getsize(string command)
    {wide=high=0;
        for(char c:command)
    {if(c=='R')
    wide++;
    else
    high++;
    }

    }
    bool translate(int x ,int y,int &resultX,int&resultY)//坐标转换，如果不在区域内返回false
    {int n=x/wide;
    int mid=high*n;//两区域中间分界线
    int top=high*(n+1);//上面的区域顶端
    int bottom=high*(n-1);//下面的区域底端
if(y<=top&&y>=mid)//in the zone//在上面的区域
{
    int left=n*wide;
    resultX=x-left;
    resultY=y-mid;
    return true;
}
else if(x%wide==0&&y<mid&&y>=bottom)//在下面的区域
{
    resultX=wide;
    resultY=y-bottom;
    return true;
}
else
 return false;
    }

    
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        bool flag=false;//标志位，判断能否具备到达终点的能力
        int resultX;
        int resultY;
        unordered_set<int> crash;
     int translateX,translateY;
        getsize(command);//获取矩形的大小;
        int finalX;//转换后的终点坐标
        int finalY;
        if(translate(x,y,translateX,translateY))
           {
            finalX=translateX;
           finalY=translateY; 
           }
        else
        {cout<<"the final target not in the zone"<<endl;
        return false;
        }
        for(int i=0;i<obstacles.size();i++)//添加所有符合条件的障碍物
       {    if(obstacles[i][0]<=x&&obstacles[i][1]<=y&&translate(obstacles[i][0],obstacles[i][1],resultX,resultY))
         crash.insert(resultX*10000+resultY);
               }
    
       int i,j;
       i=j=0;
       
        for(char c:command)//进行一轮模拟判断碰撞
        {   
            //cout<<i<<" "<<j<<endl;
            if(i==finalX&&j==finalY)
           { cout<<"can arrive"<<endl;
               flag=true;
           }    
            if(crash.find(i*10000+j)!=crash.end())
            {//cout<<"crash"<<endl;
            return false;
            }
            
            if(c=='R')
            i++;
            else
            j++;
        }
        if(flag)
     return true; 
     else
     {cout<<"can not arrive"<<endl;
         return false;}
           }
};
```


写完之后发现如果反过来Hash表存储路径然后用障碍物去查询Hash表可以省去getsize函数所花费的重复计算。
并且能在O（1）的时间对是否能到达终点做出判断。
效率应该还能提升一些吧。
