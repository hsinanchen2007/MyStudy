### 解题思路
/|(?=[-+]) 的意思是在字符是"/" 或者下一个字符是"+" 或者"-"的地方分割
"-1/2+1/2" 的结果是 ['-1', '2', '+1', '2']

在每次求解之后都要调用gcd来对分式进行约分
### 代码

```java
class Solution {
    public String fractionAddition(String expression) {
        Scanner sc = new Scanner(expression).useDelimiter("/|(?=[-+])");
        int A = 0;
        int B = 1;
        while (sc.hasNext()) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            A = A * b + B * a;
            B = b * B;
            int g = gcd(A, B);
            A /= g;
            B /= g;
        }
        return A + "/" + B;
    }

    int gcd(int x, int y) {
        if (y == 0) return Math.abs(x);
        return gcd(y, x % y);
    }
}
```