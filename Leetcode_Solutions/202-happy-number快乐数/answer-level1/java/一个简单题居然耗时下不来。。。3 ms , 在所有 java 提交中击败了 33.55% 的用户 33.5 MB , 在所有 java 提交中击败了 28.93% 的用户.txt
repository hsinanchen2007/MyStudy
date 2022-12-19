### 解题思路
1.一个计算每位数平方和的函数用于迭代
2.计算过的平方和放在哈希表里
3.平方和==1 return true；表里有相同的值陷入死循环 return false
4.正在学习大佬的快慢指针。。。

### 代码

```java
class Solution {
   
    public int count(int num){
             int val=0;
                while(num!=0){
                    val+=(Math.pow(num%10,2));
                    num=num/10;
                }
            return val;
    }
    



    public boolean isHappy(int n){
        Map<Integer,Integer> sum=new HashMap<Integer, Integer>();
        int res,step=1;
        while(true){
            res=count(n);
            if(res==1){
                return true;
            }
            else if(sum.containsValue(res)){
                return false;
            }
            sum.put(step,res);
            step+=1;
            n=res;
        }
    }
}
```