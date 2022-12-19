### 解题思路
在一百米跑道上，我们从起点走向终点要走一百个一米，若我们要从终点返回起点就要反向走一百个一米。
所以只要机器人向左走和向右走的次数一样，向上走和向下走的次数也一样，机器人就能回到起点。
有一个方法是用两个变量代表直角坐标系两个轴的移动位置，例如每向上走一次，纵轴变量就加一，每向下走一次变量减一，判断最终变量是否为初始值。第二个方法是利用函数直接判断一个轴上两个方向走的次数是否相同，相同则在那个轴上返回到了起点。

### 代码

```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        
        return (count(moves.begin(),moves.end(),'R')==count(moves.begin(),moves.end(),'L'))&&(count(moves.begin(),moves.end(),'U')==count(moves.begin(),moves.end(),'D'));

    }
};
```