![无标题.png](https://pic.leetcode-cn.com/c123235d5e20f0e93241e60009d0717085045649d4ee4d022d8b062f67354409-%E6%97%A0%E6%A0%87%E9%A2%98.png)



```
public static String convert(String s, int numRows) {
        char[] charts=s.toCharArray();
        char[] result=new char[charts.length];
        int index=0;
        int time=0;
        int c=numRows*2-2;
        if(c<=0){
            return s;
        }
        for(int i=0;i<numRows;i++){
            if(i==0){
                while (c*time<charts.length){
                    result[index++]=charts[c*time];
                    time++;
                }
                time=0;
            }else if(i+1==numRows){
                while (c*time+numRows-1<charts.length){
                    result[index++]=charts[c*time+numRows-1];
                    time++;
                }
                time=0;
            }else{
                while (c*time+i<charts.length){
                    result[index++]=charts[c*time+i];
                    if(c*(time+1)-i<charts.length){
                        result[index++]=charts[c*(time+1)-i];
                    }
                    time++;
                }
                time=0;
            }

        }
        return String.valueOf(result);
    }
```

