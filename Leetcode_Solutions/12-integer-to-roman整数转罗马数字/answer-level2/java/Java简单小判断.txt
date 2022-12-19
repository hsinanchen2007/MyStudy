按照每位整数位置进行判断。

    public static void main(String[] args) {
        int num=1994;
        char[] chars={'I','V','X','L','C','D','M'};
        StringBuilder sb=new StringBuilder("");
        int k=0;
        int length=String.valueOf(num).length();
        for (int i=0;i<length;i++){
            int t=num%10;
            if (t>0&&t<4){
                for (int j=0;j<t;j++){
                    sb.insert(0,chars[k]);
                }
            }
            else if (t==4){
                sb.insert(0,chars[k+1]);
                sb.insert(0,chars[k]);
            }
            else if (t==5){
                sb.insert(0,chars[k+1]);
            }
            else if (t<9&&t>5){
                for (int j=0;j<t-5;j++){
                    sb.insert(0,chars[k]);
                }
                sb.insert(0,chars[k+1]);
            }
            else if (t==9){
                sb.insert(0,chars[k+2]);
                sb.insert(0,chars[k]);
            }
            num=num/10;
            k+=2;
        }
        System.out.println(sb.toString());
    }