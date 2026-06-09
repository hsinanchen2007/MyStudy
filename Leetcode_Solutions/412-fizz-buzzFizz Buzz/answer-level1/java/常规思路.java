### 解题思路
先判断能否被15整除，再分别判断能否被3和5整除，否则添加该数字。

### 代码

```java
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ans = new ArrayList<>();
        for(int i = 1 ;i <= n; i++){
            String s = String.valueOf(i);
            if(i % 15 == 0){
                ans.add("FizzBuzz");
            }else if(i % 3 == 0){
                ans.add("Fizz");
            }else if(i % 5 == 0){
                ans.add("Buzz");
            }else{
                ans.add(s);
            }
        }
        return ans;
    }
}
```