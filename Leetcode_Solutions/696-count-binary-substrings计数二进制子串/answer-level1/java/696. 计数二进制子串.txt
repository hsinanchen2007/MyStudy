/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/10/8
 *
 * 解题思路: 记录连续的相同的字符的数量 并在相邻的取最小的 求他们的和   [0001111001100110101]  [3 4 2 2 2 2 1 1 1 1 ] => 3(3,4) + 2(4,2) + 2(2,2) ..... + 1(1,1)
 *
 *
 * 方式1: 使用新的数组记录连续相同的数量值
 *
 * 方式2: 采用线性扫描 pre_num cur_num 存储连续相同的数量值
 *
 */
```
 /**
    * 数组预处理
    * @param s
    * @return
    */
public int countBinarySubstrings(String s) {
    char[] s_arr = s.toCharArray();
    List<Integer> list = new ArrayList<>();
    char c = s_arr[0];
    int c_num = 0;
    for(int i = 0; i < s_arr.length;i++){
        if(c == s_arr[i]) c_num++;
        else {
            list.add(c_num);
            c = s_arr[i];
            c_num = 1;
        }
    }
            list.add(c_num);
    int res = 0;
    for(int i = 0;i < list.size() - 1;i++){
        res += Math.min(list.get(i+1),list.get(i));
    }

    return res;
}


/**
    * 线性扫描
    * @param s
    * @return
    */
public int countBinarySubstrings2(String s) {
    char[] s_arr = s.toCharArray();
    int pre_num = 0;
    int cur_num = 0;
    char cur_c = s_arr[0];
    int res = 0;
    for(int i = 0; i < s_arr.length;i++){
        if(cur_c == s_arr[i]) cur_c++;
        else {
            res += Math.min(pre_num,cur_c);
            pre_num = cur_num;
            cur_num = 1;
            cur_c = s_arr[i];
        }
    }
    res+= Math.min(pre_num,cur_c);
    return res;
}
```