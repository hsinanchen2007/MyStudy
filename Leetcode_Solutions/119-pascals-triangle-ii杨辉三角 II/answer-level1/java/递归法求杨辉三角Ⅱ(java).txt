# 一、需求
    给定一个非负索引k，其中k<=33，返回杨辉三角的第k行
# 二、分析
    A:首先新建两个List对象,其中一个当作中间变量来储存某行数据;
    B:若k==0，直接将1存到集合，并返回集合;
    C:递归结束条件,k=1时，将两个1存储到集合，并返回;
    D:递归规律，row = getRow(k-1);
    E:当最底层递归结束后，此时k=2,要存储第1行，然后回溯到k=3,存储第3行，直到k行全部存储完毕;
    F:返回集合对象;
# 三、代码实现
```
class Solution {
    public List<Integer> getRow(int rowIndex) {
        //创建对象
        List<Integer> triangle = new ArrayList<Integer>();
        List<Integer> row = new ArrayList<Integer>();
        //递归结束条件
        if(rowIndex == 0) {
            row.add(1);
            return row;
        }
        if(rowIndex == 1) {
            row.add(1);
            row.add(1);
            return row;
        }
        //开始递归
        row = getRow(rowIndex - 1);
        triangle.add(1);
        for(int j = 1; j < rowIndex; j++) {
            triangle.add(row.get(j-1)+row.get(j));
        }
        triangle.add(1);
        return triangle;
    }
}
```











