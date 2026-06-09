新增了一个Search函数，用来寻找一个数出现了几次，然后将这些数给拼接到String上
```
public String countAndSay(int n) {

        if (n == 1){
            return "1";
        }

        String str = countAndSay(n - 1);

        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < str.length(); i++) {

            int count = countAndSaySearch(str,i);

            char c = str.charAt(i);

            builder.append(count).append(c);

            i = i + count - 1;

        }

        return builder.toString();


    }

    public  int countAndSaySearch(String str,int i){

        char c = str.charAt(i);

        int count = 0;

        for (int j = i; j < str.length(); j++) {

            if (c == str.charAt(j)){
                count++;
            }else {
                break;
            }

        }

        return count;


    }

```


