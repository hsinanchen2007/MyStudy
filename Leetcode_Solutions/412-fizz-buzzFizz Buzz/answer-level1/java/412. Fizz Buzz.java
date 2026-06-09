/**
 * @Project
 * @Author zhaozhen
 * @Email 
 * @Date 2019/9/7
 * 
 * 解题思路:怎么想 怎么做
 */
```
    public List<String> fizzBuzz(int n) {

        List<String> list = new ArrayList<>();
        for(int i = 1; i <= n ;i++){
            if(i % 3 == 0 && i % 5 == 0){
                list.add("FizzBuzz");
            }else if(i % 5 == 0){
                list.add("Buzz");
            }else if(i % 3 == 0){
                list.add("Fizz");
            } else{
                list.add(String.valueOf(i));
            }
        }
        return list;

    }
```