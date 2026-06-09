### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/5d0dbcdcc9f8f328b1ea9faf31c0658c09145620cc342942fbf8dab47199dea6-image.png)

因为数组每一行是从小到大排序的,从每一行的末尾开始比较,如果目标值比行的末尾值还要大,那么目标值肯定不在这一行,然后下移一行,如果小于行的末位置,那么开始比较行的倒数第二个数,逐个比较,碰见相等就返回true,如果最终没有找到返回false

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        for(int i=0;i<matrix.length;i++){
            //取出行的数组
            int[]nums=matrix[i];
            //计算数组的最后一个元素的索引位置
            int len=matrix[i].length-1;
            //取出行的内最后一个元素,其实就是最大元素
            int num=nums[len];
            //如果恰好相等直接返回true
            if(num==target){
                return true;
            }
            //如果最大值小于target说明整行的值都小于目标值,直接跳出本次循环,进行下一次循环
            if(num<target){
                continue;
            }
            int temp=num;
            //如果target<num,开始行内元素遍历,如果遍历到temp<target说明之后的元素都小于target,就无需在遍历了
            while(temp>target&&len-1>=0){
                //索引位置减1
                len--;
                //取出对应位置的值
                temp=nums[len];
                //判断是否相等,如果相等直接返回
                if(temp==target){
                    return true;
                }
            }
        }
        //如果没有找到返回false
        return false;
    }
}
```