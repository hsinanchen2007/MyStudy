```
public int[] numberOfLines(int[] widths, String S) {
         int pos = 0,row=0;
        int[] res = new int[2];
        char[] arr = S.toCharArray();
        for(char i:arr){
            if(pos+widths[i-97]<=100){
                pos = pos+widths[i-97];
            }else{
            //如果当前字母写不下了，另起一行
                pos = widths[i-97];
                row+=1;
            }            
        }
        res[0] = row+1;res[1]=pos;
        return res;
    }
```