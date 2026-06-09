### 解题思路
核心思想：**定位到开始和结束的int，将这两个和其中间的所有int全部置为-1，然后再把线段两侧位置（两个int）通过位移运算置为0。**

由题意得我们需要构建一个vector<int>数组，int数组内形成一长串比特位，既：
/0(共32个0)0/0(共32个0)0/0(共32个0)0/......  共w/32个int，此为一行。
/0(共32个0)0/0(共32个0)0/0(共32个0)0/......  共w/32个int，此为一行。
/0(共32个0)0/0(共32个0)0/0(共32个0)0/......  共w/32个int，此为一行。
/......
/......共  length/每行int数  行。

通过题目后会变成：在某一行上，
/......
/n(n大于等与0)个0， 至少2个1 ，n(n大于等与0)个0/
/......

我们先大体定位到直线两个点所经过的int，将这些int全部置为0xffffffff，即-1；
让后我们通过x1，x2精准定位开始点所在的int左边需要空出几个0，结束点所在的int右边需要空出几个0。
然后通过位移运算把需要的0给空出来。
当x1与x2在同一个int上时，需要在右移时多移动 右边需要空出几个0 的位置，
以便把右边的1挤掉，然后通过左移再移回去,借以实现空出右边0的目的。
位移时应注意对有符号的整数进行右位移时，会以这个整数的符号补最左边的位置，
详情请google逻辑位移与算数位移。
### 代码

```cpp
class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> p(length,0);
        if (length == 0) return p;
        int row = w / 32;       //一行有多少int
        int start = row * y + x1 / 32;  //线段头所在的int
        int start_s = x1 % 32;          //线段头所在的int的左边需要空出0的个数
        int end = row * y + x2 / 32;    //线段尾所在的int
        int end_s = 31 - x2 % 32;       //线段尾所在的int的右边需要空出0的个数
        for (int i = start; i <= end; i++) {
            p[i] = 0xffffffff;          //置为-1；
        }
        if (start == end) { //对头尾在一个int里时单独处理
            p[start] = (unsigned int)p[start] >> start_s+ end_s;
            p[end] = (unsigned int)p[end] << end_s;
        }
        else {
            p[start] = (unsigned int)p[start] >> start_s;
            p[end] = (unsigned int)p[end] << end_s;
        }
        return p;
    }
};
```