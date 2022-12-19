### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> finallist = new ArrayList<List<Integer>>();
        List<Integer> temp = new ArrayList<Integer>();
        for(int i = 0;i<numRows;i++){
            List<Integer> list = new ArrayList<Integer>();
            if(i == 0){
                list.add(1);
                finallist.add(list);continue;
            }
            if(i == 1){
                list.add(1);list.add(1);temp = list;
                finallist.add(list);continue;
            }
            list.add(1);
            for(int j = 0;j<temp.size()-1;j++){
                list.add(temp.get(j) +temp.get(j+1));
            }
            list.add(1);
            temp = list;
            finallist.add(list);
        }
        return finallist;
    }
}
```