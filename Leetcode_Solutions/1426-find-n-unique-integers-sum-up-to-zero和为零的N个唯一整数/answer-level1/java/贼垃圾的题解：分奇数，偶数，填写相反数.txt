菜鸟垃圾题解。给自己看的。



```
  public int[] sumZero(int n) {
        int[] num = new int[n];
        
            //奇数
            if(n % 2 == 1){
                 for(int i = 1; i < n;i+=2){
                    //首位0
                num[0] = 0;
                    //第二位 1
                num[i] = i;
                    //第三位 -1
                num[i+1] = -i;
                 }
               
            }
            else{
                 for(int i = 0; i < n;i+=2){
                      //两个相反数  
                      num[i] = i+2;
                num[i+1] = -i-2;
                 }
               
            }
        
        return num;
    }
```
