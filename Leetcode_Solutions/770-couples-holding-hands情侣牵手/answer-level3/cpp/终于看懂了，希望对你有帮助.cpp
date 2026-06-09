耐心一步一步往下看：
1、如果并查集零基础，先看灯神视频：https://www.bilibili.com/video/av38498175?p=2 
   掌握环检测方法，一定要看后边的C语言实现，要理解视频里find_root和union_vertices 2个函数的意义

2、进入正题：题目给出情侣关系是  (0,1) (2,3) (4,5) (2N-2,2N-1)
   通过每个数字除2可以得到 (0,0) (1,1) (2,2)  ....
   把每个处理后的数字看成一个节点的话，(0,0)构成一个自己指向自己的环，环的概念很关键，新增的一条边的2个节点只要在一个集合里，一定会成环；
   那大环是什么样的？为更形象的理解我们这样表达(0-0) (1-1) (2-2)，每个扩号内是一个线段(0-1) (1-2) (2-0) 构成了大环

3、如果K对情侣坐错了位置，需要调整K-1次就可以恢复，比如（除2以前的样子）(0,2) (3,1) 需要2和1换一下位子即可  (0,1) (3,2) 
   转换成除2后的样子是：(0,1) (1,0) 也是调整1次(0,0) (1,1)

4、那么我们的问题变成了多少对情侣做错了位置，如果K，那么我们只需要调整K-1次

5、先别急，我们进入代码实现环节
   1）findroot 找到集合里的root，从当前位置一直往上找，通过递归调用并行的把根的孩子都直接挂在root下面（减少树的高度，提升效率），以前可能是
![image.png](https://pic.leetcode-cn.com/afadb3bd67788a48df48cfdce1f6013c9050e1a19f40bb84ce17c69b8a3efd45-image.png)


   2）uni：合并2个元素，先找2个元素的root，如果根相同不合并，因为本来就在1个集合里；
      如果根不同需要合并，这时存在1个问题，是谁做新的root？
      这里有个原则是，把孩子少的集合root1 挂到孩子多的集合root2下面；（相对减少树的高度，提升效率，findroot的时候都会铺平）

6、每次把2个节点除2后uni合并一下
![image.png](https://pic.leetcode-cn.com/074c46983d4c48e5cbc11eec20b31c71473dd097ed47ebf56550b90264d5486d-image.png)


7、遍历N统计大环里的节点数（也就是有多少情侣对数），即，不是自己指向自己的环(1-1)：这种属于 1的根是自己（我们这里叫做小环）
   因为在大环里root的根是自己，如果有K对做错位置，这里去掉root，统计的结果正好是K-1，这就是我们要找的答案；

![image.png](https://pic.leetcode-cn.com/55c661037b8facb7de8a891b17630fa81970e62fbe421a4eaad920e25d6163a5-image.png)

class Solution {
public:
    vector<int> parent,size;
    int findroot(int x){                   //套路代码找根，顺带把根的孩子都挂到根下
        if(x != parent[x]){ 
            parent[x] = findroot(parent[x]);
        } 
        return parent[x];
    }
    void uni(int x,int y){                 //套路代码——合并
        int xroot = findroot(x);
        int yroot = findroot(y);
        if(xroot != yroot){
            if(size[xroot] < size[yroot]){
                parent[xroot] = yroot;
                size[yroot] += size[xroot];
            }else{
                parent[yroot] = xroot;
                size[xroot] += size[yroot];
            }
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int num = row.size();  
        int N = num / 2;
        int circle = 0;
        parent = vector<int>(N,0);
        size = vector<int>(N,1);
        for(int i = 0 ; i < N ; i ++){
            parent[i] = i;
        } 
        for(int i = 0 ; i < num ; i += 2){
            uni(row[i]/2,row[i + 1]/2);   
        }
        //小环(0-0) (1-1)小环不统计   (0-2) (3-4) (5-1)-->(0-1) (1-2) (2-0)这种大环根不统计，正好等于K对情侣坐错了，要调整K-1，统计的circle就是K-1的答案；
        for(int i = 0; i < N ; i ++){
            if(i != findroot(i)){
                circle ++;             
            }                
        }
        return circle;
    }
};