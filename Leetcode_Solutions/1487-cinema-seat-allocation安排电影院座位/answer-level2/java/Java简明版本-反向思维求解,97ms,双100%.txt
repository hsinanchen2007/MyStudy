
# 题目解析 
![360截图20200322012944476.jpg](https://pic.leetcode-cn.com/5d157b30121b64f2e98852d6a91a4121549695aca80e6003d907148663ba5b5d-360%E6%88%AA%E5%9B%BE20200322012944476.jpg)

在理解了题目的大致要求之后，我们注意到数据上的一个细节(就是这个细节使得我们采用逆向思维求解的方法)：
`1 <= n <= 10^9`
  也就是说如果我们使用boolean[][]数组对所有已经被占用的座位进行记录的话，它的大小最大将会是boolean[n][10],当n取10^9的时候，显然会超出内存限制。
  那么有没有什么办法使得我们能够绕开这一过程，快速的求解呢？
  我们又注意到数据上另外的一个小细节：`1 <= reservedSeats.length <= min(10*n, 10^4)`。
  **可见被预定的座位的数量最多只有10^4个！** 
  **它们最多也就是能够分布在10^4行上！**
  这提醒了我们可以反向思考：n行座位最多能有2*n个可行的解，只需要从这些解中去掉那些因为被预定了的座位而无法满足的解即可。
  我们可以用**TreeMap<Integer,List<Integer>> map**来存储所有被预定的座位。其中，key为预定座位所在行号，value(List<Integer>)则存储该行所有被预定座位的列号。这时候我们心里有底了，因为有前面的分析，map的最大size不会超过10^4。
  为了习惯上的方便，我们的行列从0开始，行为0~n-1，列为0~9。
  **每一行简单标示为：0 1 2 | 3 4 5 6 | 7 8 9**
  显然，4个人在一行内可能坐的位置有如下三种：
```
0 1 2 | 3 4 5 6 | 7 8 9
  x x   x x
        x x x x
            x x   x x
```
即：1234/3456/5678。
并且这三种可能最多同时出现两个，即1234/5678。

**另外一件重要的事情是：每一行的关键的座位是：4,5。**
为什么呢？
从上面的图我们可以分析得出：如果4号座位被占用，那么该行最多只剩一个解(5678);5号座位被占用同理(1234)。
因此在对每一个**有被占用座位**的行进行遍历时，我们主要根据被占用座位是否含有4和5进行分类即可。
①若4，5均被占用，则该行显然无解(ans-=2;);
②5占用，4未占用，该行最多剩余一个解1234，对其特判即可；
③4占用，5未占用，该行最多剩余一个解5678，对其特判即可；
④45均未占用，此时只需分别对1234，3456，5678判断是否有解，并对8种可能的情况(实际<8种)一一列出即可。
# 代码实现
```
class Solution 
{
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) 
    {
        TreeMap<Integer,List<Integer>> map=new TreeMap<>();
        int ans=2*n;
        for(int i=0;i<=reservedSeats.length-1;i++)
        {
            int x=reservedSeats[i][0];
            int y=reservedSeats[i][1];
            if(map.containsKey(x-1))map.get(x-1).add(y-1);
            else {map.put(x-1,new ArrayList<>());map.get(x-1).add(y-1);}
        }
        //4,5 ：key / vital seats!
        for(Integer i:map.keySet())
        {
            List<Integer> list=map.get(i);
            if(list.contains(4)&&list.contains(5)){ans-=2;continue;}//4，5均被占用，该行无解，ans-=2
            else if(!list.contains(4)&&list.contains(5))//5占用，4未占用，该行最多剩余一个解1234，对其特判
            {
                if(!list.contains(4)&&!list.contains(3)&&!list.contains(2)&&!list.contains(1))ans-=1;
                else ans-=2;
            }
            else if(list.contains(4)&&!list.contains(5))//4占用，5未占用，该行最多剩余一个解5678，对其特判
            {
                if(!list.contains(5)&&!list.contains(6)&&!list.contains(7)&&!list.contains(8))ans-=1;
                else ans-=2;
            }
            else //45均未占用,分别对1234，3456，5678判断是否有解，并对8种可能的情况一一列出
            {
                boolean flag1=false;
                boolean flag2=false;
                boolean flag3=false;
                if(!list.contains(4)&&!list.contains(3)&&!list.contains(2)&&!list.contains(1))flag1=true;
                if(!list.contains(3)&&!list.contains(4)&&!list.contains(5)&&!list.contains(6))flag2=true;
                if(!list.contains(5)&&!list.contains(6)&&!list.contains(7)&&!list.contains(8))flag3=true;
                //flag1:true:可行，false：不可行
                if(flag1&&flag2&&flag3){continue;}
                else if(flag1&&flag2&&!flag3){ans-=1;continue;}
                else if(flag1&&!flag2&&flag3){continue;}
                else if(flag1&&!flag2&&!flag3){ans-=1;continue;}
                else if(!flag1&&flag2&&flag3){ans-=1;continue;}
                else if(!flag1&&flag2&&!flag3){ans-=1;continue;}
                else if(!flag1&&!flag2&&flag3){ans-=1;continue;}
                else if(!flag1&&!flag2&&!flag3){ans-=2;continue;}
            }
        }
        return ans;
    }
}
```
