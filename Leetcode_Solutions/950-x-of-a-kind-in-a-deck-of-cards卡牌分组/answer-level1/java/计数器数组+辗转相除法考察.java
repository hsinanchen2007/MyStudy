### 解题思路
1. 首先给出一个计数器数组，这个数组要大一些，把所有1 <= deck.length <= 10000的情况包含进去
2. 遍历数组，把每次数组出现的整数的个数存进数组，count[num]++;
3. 然后再遍历这个计数器数组，把出现的计数个数大于0的抽取出来，
4. 对计数数组相邻的两个元素求最大公约数，如果为1，返回false
5. 否则把公约数返回，最后判断公约数是否大于2.

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int [] count=new int[10000]; //定义一个计数器数组
        for(int i=0;i<deck.length;i++){
            int num=deck[i];
            count[num]++;
        }

        int x=0;
        for(int j=0;j<count.length-1;j++){
          //遍历的是个数,所以把为0的个数都不要
          while(count[j]>0){
            x=gcd(count[j],count[j+1]);
            if(x==1) return false; 
            j++;
          }
            
        }
        return x>=2;
    }

    public int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
}
```