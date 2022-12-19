```
class Solution {
    public int balancedStringSplit(String s) {
        char[] ar = s.toCharArray();
        int arLen = ar.length;
        int count = 0;
        int k= 0;  //R索引
        int m = 0; //L索引
        for(int i = 0; i < ar.length; i++){
            if(ar[i] == 'R'){
                k++;
            }else if(ar[i]=='L'){
                m++;
            }
            if(k == m){   //两个索引值相等则可以得到两个字符数量相同将索引赋值为0开始下一轮
                count++;
                k = 0;
                m = 0;
            }
        }
        return count;
    }
}
```
