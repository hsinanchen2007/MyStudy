这道题比较简单，但是心血来潮写了两种方式，正好一个性能最佳，一个代码最偷懒，所以写个题解。
1.字符串处理：
```
class Solution {
    public boolean checkRecord(String s) {
        if(s.length()-1>s.replace("A","").length()) return false;
        if(s.length()>s.replace("LLL","").length()) return false;
        return true;
    }
}
```

2.字符处理：
```
class Solution {
    public boolean checkRecord(String s) {
        int a = 0;
        int l = 0;
        char[] arr = s.toCharArray();
        for(char i:arr){
            if(i=='A'){
                a++;
                if(a>1) return false;
            }
            if(i=='L'){
                l++;
                if(l>2) return false;
            }else{
                l = 0;
            }
        }
        return true;
    }
}
```
