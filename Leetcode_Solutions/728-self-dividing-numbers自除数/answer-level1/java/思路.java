### 解题思路
此处撰写解题思路
我的思路:
    从left循环到right，用一个临时变量记录每次循环的值，
然后将这个值通过死循环，将这个临时记录的值一个一个的取出来，每次取
出一个判断是否为0，判断是否能够被i整除，如果可以那么就为true,如果只要不满足
一个条件那么就直接返回false，跳出循环，用if判断是否为真，为真就直接将当前循环的值添加进动态数组中！
最后返回动态数组!ok;
### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> array=new ArrayList<Integer>();
        boolean flag=false;
        int i=0;
        for( i=left;i<=right;i++){
            int n=i;
            int a=0;
            while(n>0){
                a=n%10;

                if(a!=0 && i%a==0){
                     flag=true;
                 }else{
                     flag=false;
                      break;
                 } 
                n/=10;
            }
            if(flag){
                array.add(i);
            }
        }
        return array;
    }
}
```