### 解题思路
    熟悉列表，字符串等基本的Java语法。
### 代码

```java
class Solution {
    public List<String> fizzBuzz(int n) {
        //比较简单的题，熟悉Java语法
        String fizz="Fizz";
        String buzz="Buzz";
        List <String> result=new ArrayList<>();
        for(int i=1;i<=n;i++)
        {
            StringBuilder sb=new StringBuilder();
            if(i%3==0)
                sb.append(fizz);
            if(i%5==0)
                sb.append(buzz);
            if(sb.length()==0)
                sb.append(i);
            result.add(sb.toString());
        }
        return result;
    }
}
```