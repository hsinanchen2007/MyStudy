
在杨辉三角中，下一行的每个数是在上一行中它的左上和右上两数之和，很明显可以采用“递归”的方法来解决，代码如下：

```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (numRows == 0) {
          return result;  
        } else if (numRows == 1) {
            List<Integer> list = new ArrayList<Integer>();
            list.add(1);
            result.add(list);
            return result;
        } else {
            result = generate(numRows-1);
            List<Integer> lastList = result.get(result.size()-1);
            List<Integer> list = new ArrayList<Integer>();
            list.add(1);
            for (int i = 0; i < lastList.size()-1; i++) {
                list.add(lastList.get(i) + lastList.get(i+1));
            }
            list.add(1);
            result.add(list);
            return result;
        }
    }
}
```
