### 解题思路
此处撰写解题思路
因为数组数量是固定的，所以要想得出1的位置需要利用链表去不断添加。比如10001，那么1的位置就是0和4，那么就将0和4添加到链表当中，再通过get()方法获得新链表中0和4的差值，当他们的差值为4+2n,n为正整数的时候可以计算可添加1的个数。
这样的话需要计算的情况就会有很多种
先分为两大类，一类是数组flowerbed全是0的情况，那么就计算0的个数，通过关系式找出对应可加1的个数。
另一类就是flowerbed不全为0的情况下，又分为3小类，一类是开头全是0，比如001；结尾全是0，比如100，这时候就需要算出flowerbed和链表Location之间的关系去得出开头或者结尾0的个数，从而得出可添加1的个数。最后一类就是中间为0，比如10001。
比较复杂，创建变量较多；
### 代码
```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        LinkedList Location=new LinkedList();
        int number=0;
        int m=0;
        for(int i=0;i<flowerbed.length;i++){
            if(flowerbed[i]==1){
              Location.add(i);
              m++;
            }
        } 
        if(m==0){
            number=(flowerbed.length+1)/2;
        }
        else{
        if((int)Location.get(0)!=0){
            number=number+(int)Location.get(0)/2;        
         }
        for(int i=0;i<Location.size()-1;i++){
            if((int)Location.get(i+1)-(int)Location.get(i)>=4){
                int k=(int)Location.get(i+1)-(int)Location.get(i);
                number=number+k/2-1;
            }
        }
        if(flowerbed.length-(int)Location.getLast()-1>=2){
            number=number+(flowerbed.length-(int)Location.getLast()-1)/2;
          }
        }
        if(number>=n)
        return true;
        else
        return false;
    }
}
```