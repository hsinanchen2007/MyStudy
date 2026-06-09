```

//思想：先将数组排序，然后拿饼干和孩子胃口比较，记录每次比较的位置，
//以免第二循环比较的时候出现重复比较的现象


//方法一：手写排序之后双重for()循环确定最终结果。
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        //冒泡排序 - 把胃口数组变成有序数组 （递增的）
        for(int i = 0 ; i < g.length ; i ++){
            for(int j = i+1 ; j < g.length ; j++){
                if(g[j] < g[i]){
                    int tem = g[i];
                    g[i] = g[j];
                    g[j] = tem;
                }
            }
        }
        //冒泡排序 - 把饼干大小数组变成有序数组 （递增的）
        for(int i = 0 ; i < s.length ; i ++){
            for(int j = i+1 ; j < s.length ; j++){
                if(s[j] < s[i]){
                    int tem = s[i];
                    s[i] = s[j];
                    s[j] = tem;
                }
            }
        }
        
        int k = 0;//用于定位比较字符的下标（位置）
        int num = 0;//满足的孩子数量
        for(int i = 0 ; i < g.length ; i++){
            for(int j = k ; j < s.length ; j++){
                k++;
                if(g[i] <= s[j]){
                    num++;
                    break;
                }
            }
        }
        return num;
    }
}
```
```
//方法二：原理一样,只是排序用了 java 自带方法。
        Arrays.sort(g);
        Arrays.sort(s);
        int l = 0 , r = 0;
        while(l < g.length && r < s.length){
            if(g[l] <= s[r++]) l++;
        }
        return l;
```
