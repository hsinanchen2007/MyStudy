题目很简单
唯一的问题是没有0
因此可以人为地构造0——减1
```
class Solution {
    public String convertToTitle(int n) {
        n = n - 1;
        StringBuilder sb = new StringBuilder();
        do{
            int remainer = n % 26;
            n = n / 26;
            n = n - 1;
            char t = (char)(remainer+'A');
            sb.append(t);
        }while(n>=0);
        String result = sb.reverse().toString();
        return result;
    }
}
```
