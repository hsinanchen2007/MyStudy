为什么a[i]+='a'-'A'改成a[i]=a[i]+'a'-'A'，就编译不过呢

### 代码

```java
class Solution {
    public String toLowerCase(String str) {
char[] a=str.toCharArray();
for(int i=0;i<str.length();i++){
    if(a[i]>='A'&&a[i]<='Z'){
        a[i]+='a'-'A';
    }
}
return String.valueOf(a);
    }
}
```