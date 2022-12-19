### 解题思路
使用迭代，层层生成，用时1ms

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> lists = new ArrayList<>();
        List<Integer> list1 = new ArrayList<>();
        list1.add(1);
        if(numRows == 0){
            return lists;
        }else{
            lists.add(list1);
            for(int i = 1; i < numRows; i++){//层数
                List<Integer> list = new ArrayList<>();
                list.add(1);
                for (int j = 1; j <= i - 1; j++){
                    list.add(j, lists.get(i - 1).get(j - 1) + lists.get(i - 1).get(j));
                }
                list.add(1);
                lists.add(list);
            }
        }
        return lists;
    }
}
```