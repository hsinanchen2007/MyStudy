### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public int[] sortArray(int[] nums) {
       return quickSort(nums);
    }
    public int[] quickSort(int[] numbs){
        quickSort(numbs,0,numbs.length-1);
        return numbs;
    }
    public void quickSort(int[] numbs,int star ,int end){
        //当指针不会越界时
        if (star<end) {
            //重写一遍快速排序,以左边为基点
            int res = findpoint(numbs, star, end);
            //往左边继续快速排序
            quickSort(numbs, star, res - 1);
            //往右边继续快速排序
            quickSort(numbs, res + 1, end);
        }
    }
    public int findpoint(int[] numbs ,int start , int end){
        int right = end +1 ;
        int v = numbs[start] ;
        int left = start ;
        while (true){
            //左边的坐标一直往前移动
            while (++left<=end && numbs[left]<v);
            while (--right>=start && numbs[right]>v);
            //指针相交，交换位置
            if (right<=left){
                break;
            }
            int temp = numbs[left];
            numbs[left] = numbs[right];
            numbs[right] = temp ;

        }
        numbs[start] = numbs[right];
        numbs[right] = v ;
        return right;
    }
}
```