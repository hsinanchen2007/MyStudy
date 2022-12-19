1. 关于复杂度
  1.1 时间复杂度为 O(n)
  1.2 空间负责度为 O(n)
2. 我的解题思路
  2.1 创建一个大小为源矩阵的转置矩阵大小的矩阵
  2.2 循环遍历源矩阵，将值放入对应的转置矩阵位置中

<br />
### java实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 create a matrix which its size is transpose source matrix size
     *     2.2 circulate source matrix and put element to rotate matrix
     * 3.About submit record
     *     3.1 1ms and 38.4MB memory in LeetCode China
     *     3.2 0ms and 38.3MB memory in LeetCode
     * 4.Q&A
     *
     * @param A
     * @return
     */
    public int[][] transpose(int[][] A) {
        if(A==null||A.length==0){
            return A;
        }
        int[][] res=new int[A[0].length][A.length];
        for(int i=0,len1=A.length;i<len1;i++){
            for(int j=0,len2=A[i].length;j<len2;j++){
                res[j][i]=A[i][j];
            }
        }
        return res;
    }
}
```
<br />

### php实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 create a matrix which its size is transpose source matrix size
     *     2.2 circulate source matrix and put element to rotate matrix
     * 3.About submit record
     *     3.1 28ms and 16.2MB memory in LeetCode China
     *     3.2 28ms and 16.1MB memory in LeetCode
     * 4.Q&A
     *
     * @param A
     * @return
     */
    function transpose($A) {
        if(!isset($A)){
            return $A;
        }
        $res = [];
        for($index = 0, $len = count($A[0]); $index < $len; $index++){
            $item = array_fill(0, count($A), 0);
            array_push($res, $item);
        }
        for($i = 0, $len1 = count($A); $i < $len1; $i++){
            for($j = 0, $len2 = count($A[$i]);$j < $len2; $j++){
                $res[$j][$i] = $A[$i][$j];
            }
        }
        return $res;
    }
}
```

如果你有更好的想法或者疑问，可以到 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 提出issue，我会及时处理
你也可以关注 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 获得其他题目解题思路