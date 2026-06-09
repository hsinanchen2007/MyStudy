/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 *
 * 解题思路: 主要定义一个 C_bwt 数组,向右扫描 记录当前字符距离他左边的字符C的距离 向左扫描 记录当前字符距离它右边的字符c的距离,并和左边的距离比较取最小值 O(n+n) = O(n)
 *
 * 例如:   a b l e e t c o d e l
 * 右扫描: 1 2 3 0 0 1 2 3 4 0 1
 * 左扫描: 1 2 3 0 0 1 2 2 1 0 1
 * 左边界处理: 3 2 1 0 0 1 2 2 1 0 1
 *
 */
```
 public int[] shortestToChar(String S, char C) {
    char[] S_arr = S.toCharArray();
    int[] C_bwt = new int[S_arr.length];
    int k = 1;
    int start_c_index = 10001;
    int end_c_index = 0;

    //向右扫描
    for(int i = 0;i < S_arr.length;i++){
        if(S_arr[i] == C){
            if(i < start_c_index) start_c_index = i;
            if(i > end_c_index) end_c_index = i;
            C_bwt[i] = 0;
            k = 1;
            continue;
        }
        C_bwt[i]=k;
        k++;
    }

    //向左扫描
    k = 1;
    for(int i = end_c_index;i >start_c_index;i--){
        if(S_arr[i] == C){
            k = 1;
            continue;
        }else if(k >= C_bwt[i]){
            continue;
        }
        C_bwt[i]=k;
        k++;
    }

    //边界处理(开头)
    k = 0;
    for(int i = start_c_index;i >= 0; i++){
        C_bwt[i] = k++;
    }

    return C_bwt;

}
```