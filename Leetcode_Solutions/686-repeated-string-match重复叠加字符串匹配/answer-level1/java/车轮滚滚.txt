### 解题思路
将验证字符串A首尾相连,那么可以将其看作一个滚轮
接下来使用A的字符依次印刷B,若印刷完毕则返回印刷的字符数量,其实就是B的长度
然后是B的长度减去起始索引(算一个),然后除A的长度,求上限
若印刷不成功且,长度大于A的长度,则证明循环了这时可以结束判断了
时间0,内存91.37%↑

### 代码

```java
class Solution {
    public int repeatedStringMatch(String A, String B) {
        
        /*if(A == null)return -1;
        if(B == null)return 0;
            //暴力法
            int count = B.length() / A.length();
            StringBuilder sb = new StringBuilder();
            for(int i=0;i<count;i++){
                sb.append(A);
            }
            if(B.equals(sb.toString())){
                return count;
            }
            sb.append(A);
            if(sb.indexOf(B) != -1){
                return count+1;
            }
            sb.append(A);
            if(sb.indexOf(B) != -1){
                return count+2;
            }
            return -1;*/
            //先查询是否包含A，然后比较头长度，作头操作.若符合利用loop数组看能否跑到尾，loop的计数就能算出次数
            //先看是否包含尾部(最长?不可，记录尾数组？)
        /*int i=0;
        StringBuilder sb = new StringBuilder();
        while(sb.length() < B.length()){
            sb.append(A);
            i++;
        }
        return sb.lastIndexOf(B) == -1 ? (sb.append(A).lastIndexOf(B) == -1 ? -1 : i+1) : i;*/
        //滚轮？ A作为滚轮
        char[] a = A.toCharArray();
        char[] b = B.toCharArray();
        for(int i=0;i<a.length;i++){
            int len = loop(a,b,i);
            if(len > 0){// 
                int count = 1;
                /*len -= (a.length-i);
                if(len > 0){
                    count += len/a.length;
                    count += len%a.length > 0 ? 1 : 0;
                }*/
                len = B.length() - a.length + i;
                count += len/a.length;
                count += len%a.length > 0 ? 1 : 0;
                return count;
            }else if(len + a.length <= 0){
                return -1;
            }
        }
        return -1;
        
    }
    //使用a滚轮印刷b，start为起始点
    public int loop(char[] a,char[] b,int start){
        int count = start;
        for(char c : b){
            if(a[start % a.length] != c){
                return count - start;
            }
            start++;
        }
        return 1;//start - count;
    }
}
```