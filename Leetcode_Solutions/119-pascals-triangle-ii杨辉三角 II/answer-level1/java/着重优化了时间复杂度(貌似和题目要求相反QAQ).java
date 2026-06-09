**优化了三个点**

1. 写了两遍才发现这是个全排列....
[对杨辉三角比较详细的介绍](http://math001.com/binomial_theorem/)
2. 用HashMap存值,如果是重复的部分的话就直接get 
```java
Map<Integer,Integer>map = new HashMap<>();
       for(int i=0;i<=rowIndex;i++){
           if(map.containsKey(rowIndex-i)){
               list.add(map.get(rowIndex-i));
           }
           else{
            map.put(i,cal(rowIndex,i));
            list.add(map.get(i));
           }
       }
```
3. 计算排列我换成了ln进行操作 
ln(mCn)=ln(n!)-ln(m!)-ln(n-m)!然后进一步进行优化(第一项换掉))
```java
 public static int cal(int rowIndex,int j){
        double sum =0;
        for(int i=j+1;i<=rowIndex;i++){
            sum+=Math.log(i);
        }
        for(int i=2;i<=rowIndex-j;i++){
            sum-=Math.log(i);
        }
        //由于java的精度丢失问题,我进行了四舍五入
        return (int)Math.round(Math.exp(sum));
    }
```

