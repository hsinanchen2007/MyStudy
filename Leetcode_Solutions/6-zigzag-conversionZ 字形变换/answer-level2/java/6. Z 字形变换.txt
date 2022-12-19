/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/15
 *
 * 解题思路: 通过分析发现 进行Z字的扫描中 具有以下规律(如图): 也就是 每一列每次添加的是n-1 正向添加一次(0到numRows-2) 反向添加一次(numRows-1 到 1) 每次缺省一个
 *
 * 
![EB0A719DC755ACEDAC455BA1BC963DF9.png](https://pic.leetcode-cn.com/55bcf0eebcb647857bb502c0726b38b3628b41bfa2ff04518b9d4e3062cec6dd-EB0A719DC755ACEDAC455BA1BC963DF9.png)
 *
 */

```
public String convert(String s, int numRows) {

    //边界判断
    if(numRows == 1) return s;

    char[] s_arr = s.toCharArray();
    List<StringBuilder> res = new ArrayList<>();
    int i = 0;

    //初始化
    for(i = 0;i < numRows;i++){
        res.add(new StringBuilder());
    }
    //添加第一个字符
    res.get(0).append(s_arr[0]);


    //扫描添加 每次numRows - 1 个
    i=1;
    while(i < s_arr.length){
        for(int j = 1;j < numRows && i < s_arr.length;j++,i++){
            res.get(j).append(s_arr[i]);
        }

        for(int j = numRows -2;j >= 0 && i < s_arr.length;j--,i++){
            res.get(j).append(s_arr[i]);
        }
    }

    //连接每一行 return
    StringBuilder resr = new StringBuilder();
    for(i = 0;i < numRows;i++){
        resr.append(res.get(i));
    }

    return resr.toString();
}
```