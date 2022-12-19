```
 public int maximum69Number (int num) {
        int index = -1;
        int num1 = num;
        int count = 0;
        // 求出总的位数，和最左侧的6的位数
        while(num1>0){
            count++;
            if(num1%10==6){
                index=count;
            }
            num1=num1/10;
        }
        if(index==-1) return num;
        //根据最左侧位数加上3*.......
        int add = 3;
        while(index>1){
            add = add*10;
            index--;
        }
        num = num+add;
        return num;
    }
```
