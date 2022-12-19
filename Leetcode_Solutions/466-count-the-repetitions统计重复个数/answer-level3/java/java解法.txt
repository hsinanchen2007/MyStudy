```
class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        /**
         * index为c2的索引， num1当前使用了ss1的个数， num2当前匹配的ss2的个数
         */
        int index = 0 , num1 = 0, num2 = 0;
        while(num1 < n1){
            for(int i = 0 ; i < c1.length ; i++){
                if(c1[i] == c2[index]){
                    if(index == c2.length - 1) {
                        index = 0;
                        num2 ++;
                    }else{
                        index ++;
                    }      
                }
            }
            num1++;
        }
        return num2 / n2;
    }
}
```