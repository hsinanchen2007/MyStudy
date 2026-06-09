### 解题思路
0到n代表棋盘的每列，树的深度代表每行。每个节点代表皇后的位置。通过构造树，给树剪枝。当树的深度达到n+1时就获得了其中一种解法。因为采用了树，所以不必考虑两个皇后会在同一行，只需考虑是否在同一列或同一斜线上。

### 代码
```csharp
//构造树的数据结构
public class LJtreeBean{

    public LJtreeBean Parent;
    public  string Data;
    public  int Data1;
    public int depth;
    public  List<LJtreeBean> childlist = new List<LJtreeBean>();
}

public class LJtree {

    public List<LJtreeBean> lJtreeBeanlist = new List<LJtreeBean>();
    public void AddNode(LJtreeBean n)
    {
        lJtreeBeanlist.Add(n);

    }

}
public class Solution
{
   //创建树的实例
    LJtree ljtreeins = new LJtree();
    //最终的返回结果。N皇后1那题只需要把返回值 return finish1.Count;改为return finish1;
    IList<IList<string>> finish1 = new List<IList<string>>();
    public int TotalNQueens(int n)
    {
        //先添加个根节点进去
        LJtreeBean rootnode = new LJtreeBean();
        rootnode.depth = 1;
        ljtreeins.AddNode(rootnode);
        
        //开始构造树
        addaction1(new List<int>(), rootnode, n);
        return finish1.Count;
    }

  //以4*4棋盘为例，如下图，第一行代表在棋盘的第一行四个格子中选个放皇后，第二行代表在放完第一个皇后之后，在第二行放第二个皇后，以此类推。
        //因为采用了树，所以不必考虑两个皇后会在同一行，只需考虑是否在同一列或同一斜线上。

        //               根节点
        //    0         1       2        3 
        // 0 1 2 3  0 1 2 3  0 1 2 3  0 1 2 3
        //
        //
    void addaction1(List<int> usedindex, LJtreeBean parent, int n)
    {
        for (int i = 0; i < n; i++)
        {


                usedindex.RemoveRange(parent.depth - 1, usedindex.Count - (parent.depth - 1));//清除状态，这个链表里的值代表已经添加的皇后
                if (!ishuanghouuse(usedindex, i))//剪枝，即判断是否能加入新的皇后
                {

                    LJtreeBean node = new LJtreeBean();
                    node.Parent = parent;
                    parent.childlist.Add(node);
                    node.Data1 = i;
                    node.depth = parent.depth + 1;
                    usedindex.Add(i);
                    ljtreeins.AddNode(node); //加入新的皇后
                   
                    if (node.depth != n + 1)//如果树的深度不够，说明皇后还没放完
                    {
                        addaction1(usedindex, node, n);
                    }
                    else//如果深度够了，说明求得了其中的一种解，把它加入最终要返回的链表中
                    {

            
                        //构造最终数据
                        List<string> datatemp = new List<string>();
                        while (node.Parent != null)
                        {
                            string strtemp = "";
                            for (int k = 0; k < n; k++)
                            {
                            if (k == node.Data1)
                                strtemp += "Q";
                            else
                                strtemp += ".";
                            }
                            datatemp.Add(strtemp);
                            node = node.Parent;
                        }
                        finish1.Add(datatemp);
                    }
                }

            
        }
    }


  


    bool ishuanghouuse(List<int> usedindex, int index)//判断新的皇后index是否能放进去
    {
        bool isuse = false;
        int len = usedindex.Count;
        for (int i = 0; i < len; i++)
        {
            if (usedindex[i] == index)//和之前的皇后在同一列
            {
                isuse = true;
                break;
            }


            if ((usedindex[i] == (index + len - i)) || (usedindex[i] == (index -( len - i))))//和之前的皇后在同一斜线
            {
                isuse = true;
                break;
            }

        }

        return isuse;
    }



}
```