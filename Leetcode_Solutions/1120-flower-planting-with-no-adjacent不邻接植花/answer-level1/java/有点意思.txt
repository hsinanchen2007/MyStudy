### 解题思路
这题目首先要理解是相邻花园颜色不同即可, 很容易进入要让周围的花园与自己的花颜色不一样的误区
那么只需要让自己的花颜色与邻居各不相同即可, 这里提供一个取最低位0的做法
1. 定义一个存储邻居列表的二维数组
2. 定义一个校验数组和一个取色数组
3. 接下来就是定义邻居集以及为没有花的花园种花

### 代码

```java
class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {        
        int[] result = new int[N];
        if(paths.length == 0){
            Arrays.fill(result,1);
            return result;
        }
        //ArrayList<Integer>[] map = (ArrayList[]) new ArrayList[N];
        //Queue<ArrayList<Integer>> queue = new LinkedList<>();
        int[][] map = new int[N][4];
        int[] check = {0,1,2,4,8};
        int[] refect = {0,1,2,0,3,0,0,0,4};
        // 为每个花园添加相邻花园, 最后一个位置代表待添加的索引也代表邻居个数
        for(int[] x : paths){
            int i=x[0]-1;
            int j=x[1]-1;
            map[i][map[i][3]++] = j;
            map[j][map[j][3]++] = i;
        }
        for(int i=0,tmp=0;i<N;i++,tmp=0){
            for(int j=0;j<map[i][3];j++)
                tmp |= check[result[map[i][j]]];
            //tmp+1 & ~tmp  寻找最低位的0
            result[i] = refect[tmp+1 & ~tmp];
        }
        return result;
    }  
}
```