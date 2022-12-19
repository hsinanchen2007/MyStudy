### 解题思路
c表示猜中的次数，通过直接比较获得。在除开猜中的情形中去计算伪猜中的次数，数组s,t分别表示solution和guess中字母出现的次数，取其中小的值表示伪猜中的次数，伪猜中的次数需要全部相加起来。

### 代码

```java
class Solution {
    public int[] masterMind(String solution, String guess) {
        char [] color = new char[]{'R','Y','G','B'};
        int c=0;//猜中
        int d=0;//全部猜中
        int [] s= new int[4];
        int [] t= new int[4];

        for(int i=0; i<4; i++){
            char a= solution.charAt(i);
            char b= guess.charAt(i);
            if(a==b) c++;
            else{
              for(int j=0; j<4; j++){
                if(a== color[j]) s[j]++;
                if(b== color[j]) t[j]++;              
              }          
            }          
        }
        d=getNum(s,t);
        return new int[]{c,d};
    }
    public int getNum(int []x, int []y){
        int num=0;
        for(int i=0; i<4; i++){
            if(x[i]<=y[i])
                num+=x[i];
            else
                num+=y[i];
        }
        return num;
    }
}
```