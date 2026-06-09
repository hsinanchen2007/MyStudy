### 解题思路

先统计出各个年龄的人的个数，再进行遍历条件
### 代码

```java
class Solution {
    public int numFriendRequests(int[] ages) {
        int[] count=new int[121];
        for(int age:ages) count[age]++; //统计出各个年龄的人数.
        int ans=0;
        for(int a=1;a<=120;a++){
            if(count[a]==0) continue;
        
            if(a>14) ans+=count[a]*(count[a]-1);//同龄人互发消息的条件.
            for(int b=a+1;b<=120;b++){
                if(count[b]==0) continue;
           
                if (b > 0.5 *a + 7 && b <= a && (b <= 100 || a >=100)) {  //满足a向b发消息的条件.
                    ans+=count[a]*count[b];
                }
            
                if (a > 0.5 *b + 7 && a <= b && (a <= 100 || b >=100)) { //满足b向a发消息的条件.
                    ans+=count[a]*count[b];
                }
            }
        }
        return ans;
    }
}


```