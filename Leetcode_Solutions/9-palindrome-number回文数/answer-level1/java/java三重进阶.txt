## 1、转列表取首尾比较

日常项目工程中对整取的处理其实很少，将整数的每一位取出存入list，然后取list的首尾比较即可。

代码：

```java
public boolean isPalindrome(int x) {
    // 边界条件
    if (x<0) return false;
    // 将整数每一位取出转入list
    LinkedList<Integer> q = new LinkedList<Integer> ();
    while (x!=0){
        int ele = x%10;
        q.add(ele);
        x /=10;
    }
    // 取list的首尾比较
    while (!q.isEmpty()&&q.getLast()!=null && q.getFirst()!=null){
        if (!q.getLast().equals(q.getFirst())) return false;
        // 当整数长度为奇数时跳过中间位
        if (q.size()<=1) break;
        q.removeLast();
        q.removeFirst();
    }
    return true;
}
```



## 2、直接反转整数比较

回文字符串的本质就是中心对称，所以反转后相等，就一定是回文字符串。

代码：

```java
public boolean isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reverse=0;
    int num=x;
    while (num!=0){
        reverse = reverse * 10+ num%10;
        num/=10;
    }
    return x==reverse;
}
```

## 3、反转一半整数

既然回文字符串中心对称，那左半和右半自然相等。但是要注意处理奇数长度时的中间位。

代码：

```java
public boolean isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reverse=0;
    while (x>reverse){
        reverse = reverse * 10+ x%10;
        x/=10;
    }
    return x==reverse || x == reverse/10;
}
```

