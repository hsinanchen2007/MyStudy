### 解题思路
一遍遍历字符串转换为char数组

### 代码

```java
class Solution {
    public String compressString(String S) {

        if(S==null || S.length()==0){
            return "";
        }

        char[] arr = S.toCharArray();

        char pre = arr[0];
        int count =1;
        StringBuilder sb = new StringBuilder();

        for(int i=1;i<arr.length;i++){  
            if(pre==arr[i]){
                count++;
            }else{
                sb.append(pre).append(count);
                count=1;
                pre = arr[i];
            }
        }
        sb.append(pre).append(count);
        String res = sb.toString();
        if(res.length()<S.length()){
            return res;
        } else {
            return S;
        }
        
    }
}
```