```
public static int calculate(String s) {
        boolean flag=false;//判断是否作乘的标志
        char lastAdd='+';//记录上一个+-，因为+-同级
        char lastMul='*';//记录上一个*/，因为*/同级
        int a[]=new int[2];//存储临时整形变量的栈
        int top=-1;//栈顶
        for (int i=0;i<s.length();i++){
            switch (s.charAt(i)){
                case ' ':break;
                case '+':
                case '-':
                    if (top==0)lastAdd=s.charAt(i);//遇到+-，如果栈顶是第一位，说明只有一位数，直接进栈
                    else{//栈顶不是第一位，说明是300+200-的模式，则将300+200=500  -> 500-
                        top=0;
                        a[top]=fight(a[top],lastAdd,a[top+1]);
                        lastAdd=s.charAt(i);
                    }break;
                case '*':
                case '/':
                    flag=true;//遇到*/，将flag=true，下一个数字作*/运算
                    lastMul=s.charAt(i);//*/进栈
                    break;
                default://检测到是数字
                    //检索所有相邻数字，并合并为整形
                    int num=s.charAt(i)-'0';
                    while((i+1)<s.length() && Character.isDigit(s.charAt(i+1)))
                        num = num*10+s.charAt(++i)-'0';
                    if (flag==true){                      //flag=true，当前数字与栈顶数字作lastMul(上一个*/)运算
                        a[top]=fight(a[top],lastMul,num);
                        flag=false;                       //重置flag
                    }else a[++top]=num;                   //flag=true，则直接将数字进栈
                    break;
            }
        }
        if (top==0)return a[0];                 //栈中只有一位数字
        else return fight(a[0],lastAdd,a[1]);   //模式为：300+200 或 300-200
    }

    public static int fight(int a,char f,int b){
        int result=-1;
        switch (f){
            case '+':result=a+b;break;
            case '-':result=a-b;break;
            case '*':result=a*b;break;
            case '/':result=a/b;break;
            default:break;
        }
        return result;
    }
```