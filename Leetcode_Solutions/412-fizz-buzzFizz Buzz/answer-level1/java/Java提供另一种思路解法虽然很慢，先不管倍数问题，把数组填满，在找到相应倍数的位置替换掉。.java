### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> fizzBuzz(int n) {
        String[] s=new String[n];
        for(int i=1;i<=n;i++){
            s[i-1]=i+"";
        }
        int[] arr={3,5,15};
        String[] ss={"Fizz","Buzz","FizzBuzz"};
        for(int i=0;i<3;i++){
            for(int j=arr[i];j<=n;j+=arr[i]){
                s[j-1]=ss[i];
            }
        }
        return Arrays.asList(s);
    }
}
```