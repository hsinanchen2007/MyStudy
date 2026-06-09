### 解题思路
从第一个元素遍历到最后一个元素，每个元素作为一个分割点，计算分割点右边为1的个数和左边为0的个数之和，取最小值

### 代码

java
class Solution {
    public int minFlipsMonoIncr(String S) {
       int min=Integer.MAX_VALUE;
       int number=0,count=0;
       for(int i=0;i<S.length();i++){
           number=0;count=0;
           for(int j=i+1;j<S.length();j++){
               if(S.charAt(j)=='0')
               number++;
           }
           for(int k=i-1;k>=0;k--){
               if(S.charAt(k)=='1')
               count++;
           }
           if(count+number<min)
           min=count+number;
       }
       return min;
    }
}