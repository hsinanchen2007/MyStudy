### 解题思路
 杨辉三角 发现 每一列除了首末的数为1，其余位的数是上一列 和该数相同位置的数+前一位数的和

### 代码

```java
class Solution {
    // 杨辉三角 发现 每一列除了首末的数为1，其余位的数是上一列 该数所在位置的数+前一位数的和
    public  List<List<Integer>> generate(int numRows) {
        List<List<Integer>> array = new ArrayList<List<Integer>>();
        // 二维数组 第一个循环处理第一维
        for(int i =0;i < numRows;i++){
            // 在第一维的每一行 创建一个List<Integer>
            List<Integer> subArray = new ArrayList<>();
                // 第二个循环处理第二维
                for(int j=0;j <= i;j++  ){
                    if(j == 0 || j == i){
                        subArray.add(1);
                    }else{
                        subArray.add(array.get(i-1).get(j)+array.get(i-1).get(j-1));
                    }
                }
                array.add(subArray);
        }
        return array;
    }
}
```