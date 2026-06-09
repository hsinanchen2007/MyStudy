### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        double n=Math.sqrt(c);
        int num = (int) n;
        boolean result=false;
        // System.out.println(num);
        int start=1;
        int end=num;
        if(c==0){
                result=true;
        }
        if(num==n){
                result=true;
        }
        while(start<=end){
            if((start*start+end*end)<c){
                start++;
            }else if((start*start+end*end)>c){
                end--;
            }else{
                 result=true;
                 break;
            }
        }
        return result;
    }
}
```