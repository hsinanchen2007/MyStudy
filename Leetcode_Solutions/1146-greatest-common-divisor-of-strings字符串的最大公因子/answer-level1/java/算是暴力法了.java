### 解题思路
首先两个字符串首字母不同肯定没有公因子。然后从开始往后待检测公因子一个字符一个字符的增加，当待检测公因子长度为两输入字符长度的公约数时检查是否真的是公因子，一直到遍历完较短的字符串。

执行结果ac，但是耗时和内存使用就不用说了，比较low，O(∩_∩)O哈哈~，这里仅提供一种思路

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(str1.charAt(0)!=str2.charAt(0)){
            return "";
        }
        int l1=str1.length();
        int l2=str2.length();
        int l=1;
        String ans="";
        //str2较短
        while(l<=l2 ){
            //是公约数，检查字符串
            if(l1%l==0&&l2%l==0){
                // 待检测公因子
                String tmp=str1.substring(0,l);
                //假如是公因子，拼成str1需要的次数
                int count=l1/l;
                StringBuilder sb=new StringBuilder();
                for(int i=0;i<count;i++){
                    sb.append(tmp);
                }
                //如果拼不成str1，就不是公因子了，继续往后加一个字符重新判断
                if(!sb.toString().equals(str1)){
                    l++;
                    continue;
                }
                sb=new StringBuilder();
                //假如是公因子，拼成str2需要的次数
                count=l2/l;
                for(int i=0;i<count;i++){
                    sb.append(tmp);
                }
                //如果拼不成str2，也不是公因子了，继续往后加一个字符重新判断
                if(!sb.toString().equals(str2)){
                    l++;
                    continue;
                }
                //是公因子，但可能不是最长的，临时保存下，继续往后添加字符检查
                ans=tmp;
            }
            l++;
        }
        return ans;
    }
}
```