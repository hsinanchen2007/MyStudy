### 解题思路
`并查集的应用场景是：求无向无权图连通的个数。`
下面给出一个邻接矩阵
![image.png](https://pic.leetcode-cn.com/8e7a8c53dad6a9914c89a4068928aae90bd1a50d5101b30f318f1284c796be55-image.png)
可以看到有2个连通图， 而我们就是要求这里的个数2！！

并查集的思想可以这样来比喻，这样我们用左边的图来做个示范， 如下图：
![image.png](https://pic.leetcode-cn.com/91b5b500f10403fab20b7354262037b5e75c57b3c9895d6b9d4d7954454e88f0-image.png)

开始的时候谁也不认识谁，各自为家，现在我们开始从邻接矩阵的0开始遍历（因为邻接矩阵是对角线对称的只需要考虑一般就行，我考虑上半部分）
1. 0遇到1的话，他们会打架，他们找来各自的老大（由于开始的时候各自为家，那么自己就是老大），我们这里默认1打赢了，这样1和0结成了帮派，且1就是这个帮派的帮主，代码parent[0]=1;
2. 第二天，0遇到了4，0叫来了帮主1来挑战4，4打赢了（下同，默认），那么4就成为了这个帮派的新帮主，代码parent[1]=4;
3. 第三天，0遇到了5， 0通过1叫来了帮主4, 5打赢了，那么5就成为了这个帮派的新帮主，且parent[4]=5;
4. 第四天，1遇到了3， 1通过4叫来了帮主5，3打赢了，那么3就成为这个帮派的新帮主，且parent[5]=3;
5. 第五天和第六天，是另一个帮派占领的故事（我们把上个故事讲完）
6. 第七天，3遇到7，和上面一样，7成为了新帮主
7. 第八天，4遇到5，他们通过parent一直往上找，发现自己的帮主都是7，说明已经在帮内了，不需要合并
8. 第九天，4遇到7，4的帮主是7，不需要合并
....
若天之后会有两个帮派的老大出现，分别是7和8（另一种情况自己模拟）

***当然这道题BFS和DFS都可以很快解决的，需要了解并查集的可以好好看看***
这里有一道[字节跳动——字节跳动大闯关](https://blog.csdn.net/sinat_27705993/article/details/82053102)很类似：主要思路是先构造邻接矩阵，然后BFS,DFS,并查集都能解决！！

### 如果有帮助点个赞哦！（也是刚接触并查集这个数据结构，路径压缩方法还没去了解，后面了解了再更新）
### 代码

```python3
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        parent = [-1 for _ in range(len(M))]
        print(parent)

        def find(parent, i): # 两个人碰到需要打架，但是大家直接就是通过这个函数来找帮主的
            if parent[i] == -1: return i
            return find(parent, parent[i])

        def union(parent, x, y):
            # 如果x遇到y:
            # x通过上面的函数找到帮主x_root, y通过上面的函数找到帮主y_root
            # 如果帮主一样不合并，如果不一样（默认y打赢），那么高级领导进行领域转让，并高级层服从领导即parent[y_root] = x_root
            x_root = find(parent, x)
            y_root = find(parent, y)
            if x_root != y_root:
                parent[y_root] = x_root
                # parent[x_root] = y_root 也可以（相当于用下三角进行计算）
        def union_find(Matrix):
            for i in range(len(Matrix)):
                for j in range(i, len(Matrix)):
                    if Matrix[i][j] == 1 and i!=j: # 两个人相遇
                        union(parent, i, j)
                        print(parent)
            count = 0
            for i in range(len(parent)): # 如果没有被领导，那么对于位置应该还是-1
                if parent[i] == -1:
                    count += 1
            print(parent)
            return count
        
        return union_find(M)
```