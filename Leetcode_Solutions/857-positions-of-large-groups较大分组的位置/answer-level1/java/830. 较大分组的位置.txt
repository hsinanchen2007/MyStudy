/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 * 
 * 解题思路: 线性遍历 记录连续相同字符长度 并左大于等于3判断 加入lists
 * 
 */
```
public List<List<Integer>> largeGroupPositions(String S) {
    List<List<Integer>> lists = new ArrayList<>();

    char[] S_arr = S.toCharArray();

    char cur = S_arr[0];
    int start = 0;
    int i = 0;
    for(i = 0;i < S_arr.length;i++){
        if(!(cur == S_arr[i])){
            if(i - start >= 3){
                List<Integer> list = new ArrayList<>();
                list.add(start);
                list.add(i-1);
                lists.add(list);
            }
            cur = S_arr[i];
            start = i;
        }
    }

    //不要忘了边界判断
    if(i - start >= 3){
        List<Integer> list = new ArrayList<>();
        list.add(start);
        list.add(i-1);
        lists.add(list);
    }

    return lists;

}

```