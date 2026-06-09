### 解题思路
运用substring逐个截取haystack字段,并于needle比较就可以啦

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        
        if(needle.equals("")||needle==null){
            return 0;
        }
        if(needle.length()>haystack.length()){
            return -1;
        }
        int pos=-1;
        for(int i=0;i+needle.length()<=haystack.length();i++){
            String str=haystack.substring(i,needle.length()+i);
            if(str.equals(needle)){
                pos=i;
                break;
            }
        }
        return pos;
    }
}

```