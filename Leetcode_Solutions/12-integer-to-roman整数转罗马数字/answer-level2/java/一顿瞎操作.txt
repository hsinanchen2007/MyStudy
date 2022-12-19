### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        StringBuilder s=new StringBuilder();
        Integer n=num;
        int len=n.toString().length();
        if(len==1){
            s=transNum(num,0);
        }
        if(len==2){
            s=transNum(num/10,1).append(transNum(num%10,0));
        }
        if(len==3){
            s=transNum(num/100,2).append(transNum((num%100)/10,1)).append
                    (transNum(num%10,0));
        }
        if(len==4){
             s = transNum(num / 1000, 3).append(transNum((num%1000)/100,2)).append(transNum( (num%100)/10,1)).append(transNum(num % 10, 0));
        }
        String res=s.toString();
        return res;    

    }
    private static StringBuilder transNum(int num,int zero){
        StringBuilder s=new StringBuilder();
        switch (zero){
            case 0:
                method01(s,num,"I","V","X");
                break;
            case 1:
                method01(s,num,"X","L","C");
                break;
            case 2:
                method01(s,num,"C","D","M");
                break;
            case 3:
                for (int i = 0; i < num; i++) {
                    s.append('M');
                }
                break;
        }
        return s;
    }

    private static StringBuilder method01(StringBuilder s,int num,String a,String b,String c){
        if(num<4) for (int i = 0; i < num; i++) {
            s.append(a);
        }
        if(num==4) {
            s.append(a);
            s.append(b);
        }
        if(5<=num&&num<9){
            s.append(b);
            for(int i=0;i<num-5;i++) s.append(a);
        }
        if(num==9) {
            s.append(a);
            s.append(c);
        }
        return s;
    }
}
```