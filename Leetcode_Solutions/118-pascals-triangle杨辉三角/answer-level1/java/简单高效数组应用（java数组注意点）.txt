### 解题思路
逐层解析，每一层首先添加最后一位元素，之后计算中间元素
注意：java数组存放的是地址，在更新每一位数组时，需要新建立一个数组，否则在后续改变过程中，所有数组元素都将修改。

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        ArrayList<List<Integer>> result = new ArrayList<List<Integer>>();
        if (numRows == 0) return result;
        ArrayList<Integer> current = new ArrayList<Integer>();
        current.add(1);
        result.add(current);
        if (numRows == 1) return result;
        //更新数组，以防数组同时发生改变
        current = new ArrayList<Integer>(current);
        current.add(1);
        result.add(current);
        for (int i = 3;i <= numRows;i++){
            //更新数组，以防数组同时发生改变
            current = new ArrayList<Integer>(current);
            current.add(1);
            for (int j = 0;j < result.get(i-2).size()-1;j++){
                current.set(j+1,result.get(i-2).get(j)+result.get(i-2).get(j+1));
            }
            result.add(current);
        }
        return result;
    }
}
```