```
class Solution {
    public boolean isNumber(String s) {
        if(s==null||s.length()==0) return false;

        s =s.trim();
        //定义index[0] 记录索引
        int[] index = new int[1];
        index[0] = 0;

        //先判断A
        boolean A = isInteger(s,index);

        //初始化B,C
        boolean B = false;
        boolean C =false;
        //判断B
        if(index[0]<s.length() && s.charAt(index[0])=='.'){
            index[0]++;
            B =isUnsignInteger(s,index);
        }

        //判断C
        if(index[0]<s.length() && (s.charAt(index[0])=='e'||s.charAt(index[0])=='E')){
            index[0]++;
            C = isInteger(s,index);
            if(C==false)
                return false;
        }

        return index[0] == s.length() && (A || B);
    }

    private boolean isInteger(String s,int[] index ){
        if(index[0]<s.length() && (s.charAt(index[0])=='+'||s.charAt(index[0])=='-'))
            index[0]++;

        return isUnsignInteger(s,index);
    }

    private boolean isUnsignInteger(String s,int[] index){
        int start = index[0];
        while (index[0]<s.length() && s.charAt(index[0])<='9'&& s.charAt(index[0])>='0')
            index[0]++;

        return index[0]>start;
    }


}

```
