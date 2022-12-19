### 解题思路
给定矩阵每一个1 代表边长为1的正方形,0代表不存在;
$dp[$i][$j]存储当前位置的的最大边长

这边使用循环 遍历方式存储可能存在的值

1.$x 代表矩阵的列数,$y代表矩阵的行数
2.当$i==0||$j==0||$matrix[$i][$j]==0,将对应位置的值存入
3.$dp[$i][$j]=min($dp[$i-1][$j],$dp[$i-1][$j-1],$dp[$i][$j-1])+1;
  利用min()函数比较获取边长中是否存在0,存在重新开始;
4.边长相乘

### 代码

class Solution {

    /**
     * @param String[][] $matrix
     * @return Integer
     */
    function maximalSquare($matrix) {
        $x = count($matrix[0]); //列数
        $y = count($matrix);    //行数
        $max=0;
        for($i=0;$i<$y;$i++){
            for($j=0;$j<$x;$j++){
                if($i==0||$j==0||$matrix[$i][$j]==0){
                    $dp[$i][$j]=$matrix[$i][$j];
                }else{
                    $dp[$i][$j]=min($dp[$i-1][$j],$dp[$i-1][$j-1],$dp[$i][$j-1])+1;
                    
                }
                if($dp[$i][$j]>$max)
                        $max=$dp[$i][$j];
            }
        }
        return $max*$max;     
    }
}
![1575510358(1).jpg](https://pic.leetcode-cn.com/8976c231d4e5a7125230a465aeb4fde549a1d02f1079a3bb48c2e6d81729e7b6-1575510358\(1\).jpg)



