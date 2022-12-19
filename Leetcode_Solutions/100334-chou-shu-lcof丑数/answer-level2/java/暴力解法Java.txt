
### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        List<Integer> list=new ArrayList<>();
        //第一个丑数
        list.add(1);
        int i2=0;
        int i3=0;
        int i5=0;
        while(list.size()!=n){
            int n2=list.get(i2)*2;
            int n3=list.get(i3)*3;
            int n5=list.get(i5)*5;
            int min=Math.min(n2,Math.min(n3,n5));
            if(min==n2){
                i2++;
            }
            if(min==n3){
                i3++;
            }
            if(min==n5){
                i5++;
            }
            list.add(min);
        }
        return list.get(n-1);
    }
}
```