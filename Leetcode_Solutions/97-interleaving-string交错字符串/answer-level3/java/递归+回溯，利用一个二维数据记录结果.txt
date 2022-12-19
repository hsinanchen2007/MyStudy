执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
98.57%
的用户
内存消耗 :
35.6 MB
, 在所有 Java 提交中击败了
41.14%
的用户
```
class Solution {
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
    
    public boolean isInterleave(String s1, String s2, String s3) {
         l1 = s1.length();
         l2 = s2.length();
         l3 = s3.length();
        if(l1+l2!=l3)return false;
        Boolean[][] arr = new Boolean[l2+1][l1+1];
        return cal(s1,s2,s3,0,0,0,arr);
    }
    private boolean cal(String s1, String s2, String s3, int i1, int i2, int i3,Boolean[][] arr){
        if(i3==l3)return true;
        if(arr[i2][i1]!=null)return arr[i2][i1];
        boolean res = false;
        if(i1<l1&&s3.charAt(i3)==s1.charAt(i1)){
            res = res||cal(s1,s2,s3,i1+1,i2,i3+1,arr);
        }
        if(i2<l2&&s3.charAt(i3)==s2.charAt(i2)){
            res = res||cal(s1,s2,s3,i1,i2+1,i3+1,arr);
        }
        arr[i2][i1] = res;
        return res;
    }
}
```
