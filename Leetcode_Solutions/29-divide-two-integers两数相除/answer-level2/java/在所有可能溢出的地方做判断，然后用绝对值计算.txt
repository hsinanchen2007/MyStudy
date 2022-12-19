### 解题思路
在所有可能溢出的地方做判断，用绝对值计算结果

### 代码

```java
class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend==0){
            return 0;
        }

        int result=0;

        //判断溢出(被除数为最小值，且除数为-1时会溢出)
        if(dividend==Integer.MIN_VALUE&&divisor==-1){
            return Integer.MAX_VALUE;
        }

        //防止做了绝对值运算之后溢出
        if(dividend==Integer.MIN_VALUE&&divisor==1){
            return Integer.MIN_VALUE;
        }

        if(dividend==Integer.MIN_VALUE&&divisor==Integer.MIN_VALUE){//被除数和除数为最小值，结果为1
            return 1;
        }else if(divisor==Integer.MIN_VALUE){//除数为最小值时，被除数绝对值必然小于除数，结果为0
            return 0;
        }else if(dividend==Integer.MIN_VALUE){//被除数为最小值，则先加一个除数的绝对值，并把结果+1
            dividend=dividend+Math.abs(divisor);
            result+=1;
        }

        boolean flag=false;
        //获取结果的符号
        if((dividend>0&&divisor<0)||(dividend<0&&divisor>0)){
            flag=true;//代表结果为负数
        }
        int y=Math.abs(dividend);//被除数绝对值，此时不用考虑溢出
        int x=Math.abs(divisor);//除数绝对值，此时不用考虑溢出
    
        //执行时间超出范围
        //while(y>=x){
        //    result++;
        //    y=y-x;
        //}

        result=result+div(y,x);
        return flag?0-result:result;
        
    }

    public int div(int y,int x){
        if(y<x){
            return 0;
        }
        int count=1;
        int tempx=x;
        while((tempx+tempx)<=y){
            //找到再加一个tempx值就溢出的值时也退出循环
            if(tempx>Integer.MAX_VALUE-tempx){
                break;
            }
            count=count+count;
            tempx=tempx+tempx;
        }

        return count+div(y-tempx,x);
    }
}
```