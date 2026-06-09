### 解题思路
一开始想到的方案是用哈希，但是后来速度很慢，但是其实仔细想想，是自己在处理后面的逻辑算法的时候有问题。
哈希的作用只是统计各个数据出现了几次，但是后面的处理上，完全可以处理成不断求gcd的过程。
整体处理上应该再简洁一些。
还有就是以后如果出现这种题目，直接用数组模拟，可以更快些。
要去改自己的代码了。。。

### 代码

```java
class Solution {
    //暂时想到用hashmap
    public boolean hasGroupsSizeX(int[] deck) {
        HashMap <Integer,Integer> map=new HashMap<>();
        for (int i=0;i<deck.length;i++){
            if(map.containsKey(deck[i])){
                int value=map.get(deck[i]);
                value+=1;
                map.put(deck[i],value);
            }
            else {
                map.put(deck[i],1);
            }
        }
        int len=0,min=Integer.MAX_VALUE;
        boolean flag=true;
        for(int num:map.values()){
            len++;
            min=Math.min(min,num);
        }
        if(min<2){
            return false;
        }

        int count=0;
        for(int num:map.values()){
            if(num==min){
                continue;
            }
            int temp=gcd(num,min);
            if(count==0){
                count=temp;
            }
            count=temp=count>temp?gcd(count,temp):gcd(temp,count);
            if(count!=temp || temp==1){
            return false;
            }
        }
        return true;
    }
public int gcd(int a,int b){
    if(b==0) return a;
    return a % b == 0 ? b : gcd(b, a % b);
}}
```