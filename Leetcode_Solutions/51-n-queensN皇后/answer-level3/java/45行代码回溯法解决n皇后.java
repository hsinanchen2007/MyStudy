### 解题思路
看了一些题解，思路都是差不多的，回溯法，但是代码都有些复杂，我觉得我这个还算简便，一共45行。但是我这个的缺点是用时9ms、内存消耗41.3MB。
我的代码主要都在输入格式的转换上。
1、一开始使用了一维数组`int[n+1]`来存储结果 `pos[i]=k` 代表第i行 第k列放置皇后，方便转换和理解`pos[0]`不被使用，是闲置的。
2、判断是否能攻击：`pos[i]=pos[j]` 代表放置在了同一列；`Math.abs(i-j)=Math.abs(pos[i]-pos[j])` 代表放在了一条对角线上。
3、总体思路：
    a:在每一行上依次放置皇后，放置后检查是否被攻击，直至不被攻击，在条件允许的情况下转入下一行继续:
    b:如果一直被攻击没有合适位置，清空本行放置`pos[j]=0`并转入上一行`j--`
    c:如果已经放到了最后一行，开始输出


### 代码

```java
class Solution {
    public int isplace(int[] pos, int j){
        int i;
        for(i=1;i<j;i++){
            if(pos[i]==pos[j]||Math.abs(i-j)==Math.abs(pos[i]-pos[j])){
                return 0;   //是否存在攻击，存在返回0
            }
        }
        return 1;
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> bList = new ArrayList<>();
        int i,j;
        int[] pos = new int[n+1];
        for(i = 1;i<=n;i++){
            pos[i]=0;
        }
        j=1;
        while(j>=1){
            pos[j]+=1;    //每一行顺序放置
            while(pos[j]<=n && isplace(pos,j)==0){  //检查是否溢出、存在攻击
                pos[j]+=1;
            }
            if(pos[j]<=n && j<n){   //转入下一行
                j++;
            }else{
                if(pos[j]<=n && j == n){    //放置到最后一行，开始输出
                    List<String> aList = new ArrayList<>();
                    for(int k = 1 ; k<=n;k++){
                        StringBuilder tem = new StringBuilder();
                        for(int m = 1;m<=n;m++){
                            if (m!=pos[k]) tem.append(".");
                            else tem.append("Q");
                        }
                        aList.add(tem.toString());
                    }
                    bList.add(aList);
                }
                pos[j]=0;   //回溯，本行内容清空，转入上一行
                j--;
            }
        }
        return bList;
    }
}
```