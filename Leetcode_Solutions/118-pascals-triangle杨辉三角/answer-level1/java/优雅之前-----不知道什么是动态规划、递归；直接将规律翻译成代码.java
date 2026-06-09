重要规律就是下一行除去收尾是1，中间的数字为上一行的前一位+当前为；
然后第一行和第二行，需要特别指出来；觉得没有必要把简单问题复杂化；

本来想用一个n*n的矩阵转换为列表返回；但是是二维的，不知道怎么弄了，




```
List<List<Integer>> ret = new ArrayList<>();
        if(numRows==0){
            return ret;
        }
        List<Integer> temp1 = new ArrayList<>();
        temp1.add(1);
        ret.add(temp1);
        if(numRows == 1){
            return ret;
        }
        List<Integer> temp2 = new ArrayList<>();
        temp2.add(1);temp2.add(1);
        ret.add(temp2);
        if(numRows==2){
            return ret;
        }
        for(int i = 2;i<numRows;i++){
            List<Integer> temp = new ArrayList<>();
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    temp.add(1);
                }else{
                    temp.add(ret.get(i-1).get(j-1)+ret.get(i-1).get(j));
                }
            }
            ret.add(temp);
            
        }
        return ret;
```
