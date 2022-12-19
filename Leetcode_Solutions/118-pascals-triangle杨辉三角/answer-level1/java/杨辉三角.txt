##
- 执行用时 :**1 ms**, 在所有 Java 提交中击败了**99.89%** 的用户
- 内存消耗 :34.7 MB, 在所有 Java 提交中击败了25.70%的用户
##
一点拙见，附上代码
##
```
public static List<List<Integer>> generate(int numRows){
    List<List<Integer>> list=new ArrayList<List<Integer>>();
    for(int i=0;i<numRows;i++){
        List<Integer> row=new ArrayList<Integer>();
        if(i==0){
            row.add(1);
            list.add(row);
        }else if(i==1){
            row.add(1);
            row.add(1);
            list.add(row);
        }else{
            row.add(0,1);				
            for(int j=1;j<i;j++){
                row.add(j,list.get(i-1).get(j-1)+list.get(i-1).get(j));
            }
            row.add(i,1);
            list.add(row);
        }
    }	
    return list;
}
```
