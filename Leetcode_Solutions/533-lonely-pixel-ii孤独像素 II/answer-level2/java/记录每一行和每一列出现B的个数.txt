### 解题思路
1. int[] rowsCount:记录每一行出现B的个数
2. int[] colsCount:记录每一列出现B的个数
3.  Map<String,Integer> stringMap:将每一行char数组组成一个String，记录每一个String出现的次数（不等于N的肯定就不是目标行了。）提高效率。
4. int[][] colsRowIndex =new int[rows][N+1]：记录每一列出现X个B的行号。第0位不存值。
   例如：第1行出现了3个B(分别在2，4,5列)。那么记录为：
   colsRowIndex[1][1]=2 //第1行中第1次出现B的列号为2
   colsRowIndex[1][2]=4 //第1行中第2次出现B的列号为4
   colsRowIndex[1][3]=5 //第1行中第3次出现B的列号为5

### 代码

```java
class Solution {
 public int findBlackPixel(char[][] picture, int N) {
        if(null==picture||picture.length<N)
        {
            return 0;
        }
        int rows = picture.length;
        int cols = picture[0].length;
        //记录每一行出现B的次数
        int[] rowsCount = new int[rows];
        //记录每一列出现B的次数
        int[] colsCount = new int[cols];
        //记录每一列中出现了B的行号(前N个出现的)
        int[][] colsRowIndex =new int[rows][N+1];
        Map<String,Integer> stringMap = new HashMap<>();
        for(int i=0;i<rows;i++)
        {
            //将每一行的字符组成一个字符串，快速对比是否一致。
            String str = new String(picture[i]);
            if(stringMap.containsKey(str))
            {
                int value = stringMap.get(str)+1;
                stringMap.put(str,value);
            }else {
                stringMap.put(str,1);
            }

            for(int j=0;j<cols;j++)
            {
                if(picture[i][j]=='B')
                {
                    rowsCount[i]++;
                    colsCount[j]++;
                    //第i行的第rowsCount[i]中，每一个B出现的列号：第j列
                    if(rowsCount[i]<=N) {
                        colsRowIndex[i][rowsCount[i]] = j;
                    }
                }
            }
        }
        //找到孤独像素所在的行，判断他们的每一个坐标的值都相等
        int count=0;
        String preRows=null;
        for(int i=0;i<rowsCount.length;i++)
        {
            if(rowsCount[i]!=N)
            {
                continue;
            }
            if(preRows == null)
            {
                preRows =new String(picture[i]);
            }
            String currentString = new String(picture[i]);
            //如果这一行出现的频率不等于N，说明不是可能的候选结果
            if(stringMap.getOrDefault(currentString,0)!=N)
            {
                continue;
            }
            //从colsRowIndex取出包含N个B的行的坐标
            int[] perRowIndex =  colsRowIndex[i];
            //遍历每一个列
            for(int j=1;j<perRowIndex.length;j++)
            {
                if(colsCount[perRowIndex[j]]==N)
                {
                    count++;
                }
            }
        }
        return count;
    }
}
```