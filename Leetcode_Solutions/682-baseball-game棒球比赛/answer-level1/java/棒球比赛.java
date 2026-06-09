### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int calPoints(String[] ops) {
        int [] arr=new int[ops.length];
        int i=0;
        for(String s:ops)
        {
            switch(s){
                case "+": arr[i]=arr[i-1]+arr[i-2];  i++;  break;
                case "D": arr[i]=arr[i-1]*2;  i++;  break;
                case "C": arr[i-1]=0; i--; break;
                default :
                    arr[i]=Integer.valueOf(s);
                    i++;
            }
        }
        int sum=0;
        for(i=0;i<arr.length;i++)
            sum+=arr[i];
        return sum;
    }
}
```