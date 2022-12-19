public List<String> fizzBuzz(int n) {

        List<String> list=new LinkedList<>();
        String str1="Fizz";
        String str2="Buzz";
        String str3="FizzBuzz";
        int a=3;
        int b=5;
        for(int i=1;i<=n;i++){
            if(i==a && i==b){
                list.add(str3);
                a+=3;
                b+=5;
            }
            else if(i==a){
                list.add(str1);
                a+=3;
            }
            else if(i==b){
                list.add(str2);
                b+=5;
            }
            else
                list.add(String.valueOf(i));


        }

        return list;
    }