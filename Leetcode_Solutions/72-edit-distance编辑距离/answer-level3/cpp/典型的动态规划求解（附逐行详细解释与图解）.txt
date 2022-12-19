### 解题思路
* 问题拆分：

对于动态规划问题，思路应该是先寻找子结构，将大问题拆成小规模的小问题
所以对于两个长的字符串之间的转化，应该先从它们各自的一部分之间转化进行入手
比如对于"ab"转化为"bc",针对最后一步变成bc，我们可以这么考虑来找它的来源：
**ab通过一系列转变变为了bcb**，再删个b
**ab通过一系列转变变为了b?**，?转化为c
**ab通过一系列转变变为了b**，再加个c
对于最后一步只有这三种考虑的情况
那么接下来我们只需要考虑粗体字体中的上一步来源，同样也是三种考虑情况
那么我们怎么才能合理的存储每一步之前发生过的三种情况呢？


* 数据存储：    

再次看刚刚这个案例
||NULL|a|b|
|:-:|:-:|:-:|:-:|
|NULL|略|略|略|
|b|略|这里存放a转换为b的最少操作数|这里存放ab转换为b的最少操作数|
|c|略|这里存放a转换为bc的最少操作数|这里存放ab转换为bc的最少操作数|
显然可以利用二维数组进行存储
并且可以根据每个格子的左边格子，上边格子，左上格子的三个最优解获得当前格子应该存储的最优解
动态规划相比暴力检索不同的就是动态规划会把之前计算过的数据合理的存储起来再次利用
那么这道题我们将每一步的最优解都存储在一个二维数组中，然后根据二维数组中已有的数据计算当前格子的数据


* 每步最小操作数计算：

以上面表格中的例子举例比较易懂

对于ab->bc上面的格子，存储了ab->b的最小步数，如果ab->b->bc那必然会插入一个c，步数加一。

对于ab->bc左上的格子，存储了a->b的最小步数，a->b变为ab->bc因为最后位置字符的不同，必然会加一步数
但是假如是ab->bb，那么步数在a->b基础上就不变。

对于ab->bc左边的格子，存储了a->bc的最小步数，如果是ab->bc，就会变为**a**b->**bc**b->bc
在原有基础上必然会删去一个b，步数加一。

最后将这三个获得的值进行比较，其中最小的那个就是当前两个字符串转换所需要的最小步骤数
以下为"ab"转化为"bc"的全数据，a->b详细描述了这一步得来的计算过程
||NULL|a|b|
|:-:|:-:|:-:|:-:|
|NULL|NULL->NULL,0步|a->NULL,1步|ab->NULL,2步|
|b|NULL->b,1步|(上格子)a->NULL基础上计算a->b,要插入一个b,1+1=2步<br>(左上格子)NULL->NULL基础上计算为a->b,要改变一个a,0+1步<br>(左格子)NULL->b基础上计算a->b,要删除一个a,1+1=2步<br>故此处最少1步  |ab->b,1步<br>包含a->NULL(1步),ab->b(0步)|
|c|NULL->bc,2步|a->bc,2步<br>包含a->b(1步),b->bc(1步)|ab->bc,2步<br>包含a->b(1步),ab->bc(1步)<br>或者ab->b(1步),b->bc(1步)|


* 实例图解：

所以根据以上思想对两个长的字符串进行从上到下，从左到右的填充二维数组中的值即可
在最初初始化边界时，从空字符串转化为非空字符串或从非空字符串到空字符串的步数显而易见
以下为word1 = "intention", word2 = "execution"实例生成的二维数组，供大家思考
**再强调一下，每一步的计算都是根据左、上、左上三个格子中的值计算，并取最小得来的**
![@9)QGW{JL2T3UP~\]W@3S~92.png](https://pic.leetcode-cn.com/eaf6127b9a6e04cb3052a7e26b3e1c396b02a98b205599099142a4d239455a42-@9\)QGW%7BJL2T3UP~%5DW@3S~92.png)
最终答案即是二维数组最右下角格子里的值

### 代码
以下为注释版本代码：
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        //如果某一字符串长度为0，答案必为另一字符串长度
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();
        //opt存储的是word1[1]~word1[j]这一j长度字符串
        //转化到word2[1]~word2[i]这一i长度字符串所需的最小操作数
        int opt[word2.size()+1][word1.size()+1];
        //opt这个二维数组的意义是在计算未填充的二维数组内容时候可以对之前填充过的数据进行借鉴
        //当填充到opt[word2.size()][word1.size()]这个数时，即得到我们需要的答案
        //动态规划的本质就是站在之前的工作基础上做当前工作，避免重复工作从而降低复杂度

        //从左到右，从上到下的顺序对格子进行填充
        for(int i=0;i<=word2.size();i++){
            for(int j=0;j<=word1.size();j++){
                //空字符串之间的转化次数就是非空字符串长度
                if(i==0){
                    opt[i][j]=j;
                    continue;
                }
                if(j==0){
                    opt[i][j]=i;
                    continue;
                }
                //a存储当前格子左边格子计算得出的数值
                //b存储当前格子左上格子计算得出的数值
                //c存储当前格子上格子计算得出的数值
                //为什么加1在解题思路里有详细解释
                int a=opt[i][j-1]+1;
                int b;
                if(word1[j-1]==word2[i-1]) b=opt[i-1][j-1];
                else b=opt[i-1][j-1]+1;
                int c=opt[i-1][j]+1;
                //取三者最小值
                opt[i][j]=min(min(a,b),c);
            }
        }
        return opt[word2.size()][word1.size()];
    }
};
```
以下为无注释版代码：
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();
        int opt[word2.size()+1][word1.size()+1];
        for(int i=0;i<=word2.size();i++){
            for(int j=0;j<=word1.size();j++){
                if(i==0){
                    opt[i][j]=j;
                    continue;
                }
                if(j==0){
                    opt[i][j]=i;
                    continue;
                }
                int a=opt[i][j-1]+1;
                int b;
                if(word1[j-1]==word2[i-1]) b=opt[i-1][j-1];
                else b=opt[i-1][j-1]+1;
                int c=opt[i-1][j]+1;
                opt[i][j]=min(min(a,b),c);
            }
        }
        return opt[word2.size()][word1.size()];
    }
};
```