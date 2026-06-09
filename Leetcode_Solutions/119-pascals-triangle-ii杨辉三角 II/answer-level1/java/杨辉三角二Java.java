### 解题思路
最直脑筋的做法就是直接生成一个杨辉三角，然后返回三角的第k值

但我们知道杨辉三角的每一行都只与前一行相关，所以我们可以只保留两个，前一行和当下这行
最终返回cur

第一种直观的做法是创建两个ArrayList，分别是pre和cur

但仔细思考，其实可以省略掉pre的创建，在for镶嵌循环里，还没有更新前的cur可以当做是前一行
每次获得cur的一个元素，保存为temp，

内循环结束前将当下的第j个元素temp赋值给pre，进入下一个内循环

最终返回cur

太晚了，随便写写

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        int pre = 1;
        List<Integer> cur = new ArrayList<>();
        cur.add(1); //这里只需要记录每层的信息
        
        for(int rowNum = 1; rowNum <= rowIndex; rowNum ++){
            for(int j = 1; j < rowNum; j++){
                int temp = cur.get(j);
                cur.set(j, pre + temp);
                pre = temp;
            }
            cur.add(1);
        }

        return cur;

    }
}
```

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {

        直接用杨辉三角的方法来做
        List<List<Integer>> triangle = new ArrayList<>();
        
        triangle.add(new ArrayList<>());
        triangle.get(0).add(1);

        if (rowIndex == 0) return triangle.get(0);

        for(int rowNum = 1; rowNum <= rowIndex; rowNum++){
            List<Integer> temp = new ArrayList<>();
            List<Integer> preRow = triangle.get(rowNum - 1);

            temp.add(1);
            for(int i = 1; i < rowNum; i++){
                temp.add(preRow.get(i - 1) + preRow.get(i));
            }
            temp.add(1);

            triangle.add(temp);
        }
        return triangle.get(rowIndex);
    }
}
```