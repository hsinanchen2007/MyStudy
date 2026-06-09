```
class Solution {
    public boolean isUnique(String astr) {
         if(astr.length()<2)
            return true;
        char[] arr = astr.toCharArray();
        int p=0;
        for(int i=0;i<arr.length;++i){
            if(((1<<(arr[i]-'a'))&p)!=0){
                return false;
            }
            p|=(1<<(arr[i]-'a'));
        }
        return true;
    }
}
```
评论区的JAVA真是看到我头大。。 自己写一个