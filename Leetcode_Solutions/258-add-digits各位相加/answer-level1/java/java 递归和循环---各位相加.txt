 ** 第一种循环，用/10把十位数取出来,%10把个位数取出来，一直循环，直到小于10，就是结果了**

//非递归
    public int addDigits(int num) {
       int sum=0;
       while (num>10){
           num=num/10+num%10;
       }
       // System.out.println("-->"+num);
        return num;
    }



  **第二种递归,用/10把十位数取出来,%10把个位数取出来，一直递归，小于10时，把结果返回**
public int addDigits2(int num) {
        if(num<10){
            return  num;
        }
        return addDigits2(num/10+num%10);
    }