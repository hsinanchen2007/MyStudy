### 解题思路
这无非是替换操作，如{ [1 ,2 ,3 ,4 ],
                    [5 ,6 ,7 ,8 ],
                    [9 ,10,11,12],
                    [13,14,15,16]
                    }

先想最外围第一圈第一个数 1,4,16,13,各自的值怎么替换，就是代码中最核心的位置
然后再2，8，15，9的值怎么得到，无非是某个参数++和--的操作
接着3，12，14，5，也同样是某个参数++和--的操作，
所以while循环来处理，将某个参数作为条件，如代表1到3 ++的参数

第一圈完了还有里面一圈，n*n一共有n-2圈，这些圈又是同样的操作，再写个while包含里面的while循环，大圈到小圈

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int i=0;
        int j=matrix.length-1;

while(i<j){
        int bel=i;//matrix[0][i];
        int enh=i;//matrix[i][0];
        int enl=j;//matrix[0][i];
        int beh=j;//matrix[i][0];
    while(bel<j)
        {
            int k=matrix[i][bel];
            matrix[i][bel]=matrix[beh][i];//左1=左1下
            matrix[beh][i]=matrix[j][enl];//左1下=右尾下
            matrix[j][enl]=matrix[enh][j];//右尾下=右尾上
            matrix[enh][j]=k;//右尾上=左1上
            bel++;
            enh++;
            beh--;
            enl--;
        }
        i++;
        j--;


}


        
        



    }
}
```