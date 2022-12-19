现有两个水壶
一个容量为xL 一个容量为yL
设x>y
**通过容量差异构造差值的方式来构造不同的水量 直到构造的水量等于zL(返回true)或出现重复(返回false)**
故有如下过程:
首先构造出x-y的水量 
将x水壶装满 此时y水壶**可用容积**为yL 再倒入y水壶中直至y水壶被装满 构造出新的水量(x-y)L 做标记
此时(x-y)L放置在x水壶中 y水壶装满
然后倒掉y水壶中的水 将(x-y)L水一次性或分批倒入y水壶中
再将x水壶装满 此时y水壶**可用容积**为(y-(x-y))L 再倒入y水壶中直至y水壶被装满 构造出新的水量(y-(x-y))L 做标记
此时(y-(x-y))L放置在x水壶中 y水壶装满
再依次重复以下过程：
倒掉y水壶中的水 将X水壶中的水一次性或分批倒入y水壶中
装满x水壶 再倒入y水壶中直至y水壶被装满 构造出新的水量 做标记
直到构造的水量等于zL(返回true)或出现重复(返回false)
注意在此过程中要加上xL或yL 因为可能两个水壶的总量和等于z
注意x水壶中的剩余水量可能一次也可能分多次倒入y水壶中

完整代码如下

```
bool canMeasureWater(int x, int y, int z){
int temp;
if(z==0||x+y==z) return true;
if(x==0||y==0) return false;
if(x<y)
{temp=x;
x=y;
y=temp;}
int vis[x+1];
memset(vis,0,sizeof(vis));
temp=0;
while(1)
{temp=x-(y-temp);
if(temp==z||temp+y==z) return true;
if(!vis[temp])vis[temp]=1;
else return false;
while(temp>y)
{temp-=y;
if(temp==z) return true;
if(!vis[temp])vis[temp]=1;
else return false;}
if(temp+x==z) return true;
}
}
```
时间复杂度：o(max(x,y)) 会构造出很多的水量 但构造出的水量一定小于max(x,y) 故状态数最多为max(x,y) 大于此状态数一定会出现重复
空间复杂度: o(max(x,y)) 来源于标记数组

运行结果：
![捕获.PNG](https://pic.leetcode-cn.com/9cfb48834154466cae85aacaa3710a17aa0fdfaacfe5ad89f008efdcd5bcc2eb-%E6%8D%95%E8%8E%B7.PNG)
这种解法虽然不如答案中的数论解法快 但有一个好处就是可以将倒水过程输出 而答案的数论解法仅能判断是否能够成功
而答案中的搜索解法虽然也能输出倒水过程 但不如这种解法快 
所以这种模拟过程解法综合性能较高