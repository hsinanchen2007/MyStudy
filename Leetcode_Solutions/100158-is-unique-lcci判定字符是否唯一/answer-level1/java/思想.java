### 解题思路
此处撰写解题思路
我的思路：
    先判断字符串是否为空，如果为空就返回真
    再次判断字符床的长度是否为1，如果为1的时候也为真

    其次我用了比较排序算法，本来是用来比较数组的顺序的，没想到可以用来比较前一个字符和后一个字符
只要前面一个字符的和后面的字符不一样的时候就记录下来为真，只要不相同的话就直接返回为false;
### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        boolean flag=false;
        if(astr.equals("")){
            return true;
        }
        if(astr.length()==1){
            return true;
        }
        for(int i=0;i<astr.length()-1;i++){
            for(int j=i+1;j<astr.length();j++){
                if(astr.charAt(i)==astr.charAt(j)){
                    return false;
                }else{
                    flag=true;
                }
            }
        }
        return flag;
    }
}
```