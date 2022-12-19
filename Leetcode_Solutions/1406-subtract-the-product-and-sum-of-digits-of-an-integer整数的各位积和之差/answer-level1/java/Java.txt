### 解题思路
此处撰写解题思路
时间复杂度：while（）循环所执行次数为s.length()次，O（s.length（））
空间复杂度：定义了pro,sum,value,s,A,i,所以O(6)
### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int pro=1;  // 乘积初始化
        int sum=0;  //和初始化
        int value=0;
        String s=""+n;  //将整数转换为字符串方便求长度
        int []A= new int[s.length()];
        int i=0;
        while(n>0){
            A[i]=n%10;  //可以省略中间的A[i]直接赋值
            sum+=A[i];
            pro*=A[i];
            n/=10;
            i++;
        }
        value=pro-sum;
        return value;
    }
}
```