``` java
class Solution {
    public String generateTheString(int n) {
        char a = 'a';
        char b = 'b';
        char c = 'c';
        char[] result = new char[n];
        for(int i=0;i<n-1;i++){
            result[i] = a;
        }
        result[n-1] = b;
        if(n%2!=0&&n>1){
            result[n-2] = c;
        }
        return String.valueOf(result);
    }
}
```
直接填充result数组，确保有1个b和n-1个a，如果n为偶数那么n-1也为奇数
如果n为奇数那么n-1为偶数，所以就要把下标为n-2的a换成另外一个字母