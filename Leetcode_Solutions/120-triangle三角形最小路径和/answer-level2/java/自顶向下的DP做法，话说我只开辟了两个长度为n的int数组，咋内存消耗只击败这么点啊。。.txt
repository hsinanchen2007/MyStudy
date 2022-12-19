### 解题思路
![QQ截图20200325175041.png](https://pic.leetcode-cn.com/c69078e20ec37c10fd0199b5213b1789e6f79e18e15fc737cc102ea33346093a-QQ%E6%88%AA%E5%9B%BE20200325175041.png)

自顶向下的DP做法，做着比较有意义的一道DP题，充分发扬了最大子段和及其衍生问题中“**以当前元素为结尾，从线性dp表中取其中最大/小元素**”的核心思想

以下是我的做法：
因为所谓的最小路径和，一定是以最后一行某一个元素为结尾的，只是现在不知道是哪一个元素而已，一共就n（n为行数,也是最后一行元素个数）种可能，遍历即可

dp_min[j]表示对于当前正在处理行的每一个元素，以第j个元素为结尾的最小路径和，dp_min最多容纳n个元素，在最后一次循环对最后一行各元素处理完以后，取最小的dp_min元素即可

temp_last_row[j]是临时数组，用来保存上一行的运算结果，因为对本行的dp_min进行赋值时，需要用到上次循环的结果,于是把上次的dp_min赋给temp_last_row保存

状态转移方程：

对于第(i+1)行

dp_min[j]={

temp_last_row[0]+triangle[i][j],if j==0;//当前行第一个元素下标


temp_last_row[j-1]+triangle[i][j],if j==i;//当前行最后一个元素下标


min(temp_last_row[j],temp_last_row[j-1])+triangle[i][j], if 0<j<i//中间元素

}
初始化dp_min[0]=triangle[0][0]

当最后一行处理完，此时dp_min存着以最后一行每个节点为结尾的最小路径和，取其min





lc不缺大佬，更不缺优秀的题解，像我这种超级大菜逼却还频繁发布题解，原因有二:
一是为了给自己留作纪念，以供将来复习，别人的代码，我看一遍就忘了，哪怕看懂了，让我用别人的思路做这题我恐怕也写不出来，可我自己写的代码，哪怕是过一个月再看，只要看一遍应该也能写出来（当然如果自己的思路太差劲的时候，我也知道要努力学习大佬的思想）
二是为了让走过路过的朋友都看看，在lc还有我这样的大菜逼，估计也能增长增长过客们的自信心
所以如果代码很糟糕，想法很垃圾，请朋友们轻喷

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
       //行数必>=1,且列数必>=1,不然空树该返回什么作为最小值呢？
        int row=triangle.size();//行数
        int max_col=row;//最后一行的元素个数，即dp表最大的可能的容量
        int []dp_min=new int[max_col];//在第i行中，dp_min[j-1]表示以triangle[i-1][j-1]节点结尾的（注：此时，从根到第i行的路径必包含triangle[i-1][j-1]作为结尾）路径的最小长度
        //当i<=row时，设col=第i行的元素个数，则dp_min只用到了前col个位置，其中1<=i<=row,1<=j<=max_col
        //当循环完第row行，此时的dp_min就是以最后一行各个元素为终点的最小路径和，取min(dp_min)即可
        dp_min[0]=triangle.get(0).get(0);//第一行
        
        int [] temp_last_row=new int[max_col];//临时数组，用于保存上一次循环的dp表结果，即上一行的dp值
        //实际最多上只用到了前“倒数第二行元素个数”，这么多个位置，这里以最后一行元素个数为大小开辟空间是为了防止只有一个元素时负溢出
        
        for(int i=1;i<row;i++){//从第二行开始循环，i与上面注释的i不同，这里是下标
            
            for(int x=0;x<triangle.get(i-1).size();x++) temp_last_row[x]=dp_min[x];//每次只需要做上一行元素个数的次数的赋值
            
            int this_col=triangle.get(i).size();//本行列数
            
            for(int j=0;j<this_col;j++){//i，j直接用作下标
                if(j==0) dp_min[j]=temp_last_row[j]+triangle.get(i).get(j);//上一行的相邻元素只一个，本行[0] 的上一行相邻元素是 上一行[0]
                else if(j==this_col-1) dp_min[j]=temp_last_row[j-1]+triangle.get(i).get(j);//上一行的相邻元素只一个
                else{
                    dp_min[j]=Math.min(temp_last_row[j],temp_last_row[j-1])+triangle.get(i).get(j);//上一行的相邻元素有两个
                    //即上一行的 [j]和[j-1]
                }
                
            }
            
        }
        int min_res=dp_min[0];

        for (int min_in_dp:dp_min
             ) {
            if(min_in_dp<min_res) min_res=min_in_dp;
            
        }//取最大的dp_min元素
       
       return min_res;


    }
}
```