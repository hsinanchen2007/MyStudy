```
// 给定长度=行数numRows
List<List<Integer>> oa = new ArrayList<>(numRows);
for(int i = 1; i < numRows + 1; i++){
    //元素集合
    List<Integer> ia = new ArrayList<>(i);
    for(int j = 0; j < i; j++){
        //如果是开头或者结尾就补1，第一行和第二行都会走这里，所以不用再判断。
        if(j == 0 || j == i - 1) {
            ia.add(j, 1);
        } 
        // 其他就拿外层集合的上一个元素对应的，本序号+上序号之和。（为什么-2因为i是从1开始的）
        else {
            ia.add(j, oa.get(i-2).get(j-1) + oa.get(i-2).get(j));
        }
    }
    oa.add(ia);
}
```

