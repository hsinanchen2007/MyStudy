### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S == null || S.length() == 0){
            return "";
        }

        StringBuilder res = new StringBuilder();
        char pre = S.charAt(0);//记录上一个字符
        int times = 1;//记录字符频率

        for(int i = 1; i <S.length(); i++){
            char cur = S.charAt(i);
            if(cur == pre){
                times += 1;
            } else{
                res.append(pre).append(times);
                pre = cur;
                times = 1;
            }


        }

        res.append(pre).append(times);

        if(res.length() >= S.length()){
            return S;
        }
        return res.toString();

    }
}
```