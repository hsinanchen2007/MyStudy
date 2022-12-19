
结合了各位大神的代码
 
 题目说0<=N<=500
    1.如果采用暴力解法O(n^4)
      500^4=62500000000 这样计算机承受不了
    2.利用查找表将D放入查找表中 遍历A、B、C在查找表中找是否存在-A、-B、-C
      这样的话时间复杂度为O(n^3)
      500^3=125000000还是太大了
    3.如果能将其化解为O(n^2)的算法
      500^2=250000这样是可以接受的
      故只需要将C+D的每一种可能放入查找表（map） 
    这样我们只需要寻找这个表里面有没有-A-B就行了 
    有的话则A+B+C+D=0，然后统计一下个数


将数组C，D 任意组合的和存入查找表中， key是和，value 是出现的次数。记录A，B 任意组合的和的负值，然后在查找表中查找是否有对应的值
时间复杂度：O(n^2。

```
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        HashMap<Integer,Integer> map=new HashMap<>();
        
        int sum=0;
        for(int i=0;i<A.length;i++){
            for(int j=0;j<B.length;j++){
                sum=A[i]+B[j];
                if(map.containsKey(sum)){
                    map.put(sum,map.get(sum)+1);
                }else{
                    map.put(sum,1);
                }
                
            }
        }
        
        int count=0;
        int sum2=0;
        for(int i=0;i<C.length;i++){
            for(int j=0;j<D.length;j++){
                sum2=-C[i]-D[j];
                if(map.containsKey(sum2)){
                    count+=map.get(sum2);
                }
                
                
            }
        }
        return count;
            
    }
}
```

```
class Solution {//自主：219ms 44%;一个map
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer,Integer> map=new HashMap();
        int count=0;
        for(int a:A)
            for(int b:B)
                map.put(a+b,map.getOrDefault(a+b,0)+1);        //若有a+b这个key则用它的值+1，若没有就用默认的0
        for(int c:C)
            for(int d:D)
                count+=map.getOrDefault(-c-d,0);        //若有-c-d这个key就用它的值，代表-c-b=a+b
        
        return count;
    }
}
```
