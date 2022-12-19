### 解题思路
同上述118几乎一样的解题思路

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> list = new ArrayList<>();
//这里必须要加上1，因为题目说返回第三行其实指的是第四行
        for(int i=0;i<rowIndex+1;i++){
        List<Integer> tmplist=new ArrayList<>();
//得到前两行
            if(i<2){
                for(int j=0;j<=i;j++){
                    tmplist.add(1);
                }
                list.add(tmplist);
            }
//剩下行
            else{
                tmplist.add(1);
                for(int j=1;j<i;j++){
                    tmplist.add(list.get(i-1).get(j-1)+list.get(i-1).get(j));
                
                }
                tmplist.add(1);
                list.add(tmplist);
            }
        }
//返回rowIndex行。
        return list.get(rowIndex);
    }
}
```
118题的解题

 ```java
public  static List<List<Integer>> generate(int nums){
        List<List<Integer>> list = new ArrayList<>();
        for(int i=0;i<nums;i++){
            List<Integer> tmpList = new ArrayList<>();
            if(i<2){
                for (int j = 0; j <= i; j++) {
                    tmpList.add(1);
                }
                list.add(tmpList);
            }
            else{
                tmpList.add(1);
                for (int j = 1; j <i ; j++) {
                    int sum = list.get(i - 1).get(j - 1) + list.get(i - 1).get(j);
                    tmpList.add(sum);
                }
                tmpList.add(1);
                list.add(tmpList);
            }

        }
        return  list;
    } ```