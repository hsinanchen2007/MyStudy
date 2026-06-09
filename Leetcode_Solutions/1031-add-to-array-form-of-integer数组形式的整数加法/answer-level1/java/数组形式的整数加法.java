### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        ArrayList<Integer> list=new ArrayList<>();
            int x=A.length-1;
            String a=""+K;
            int len=a.length();
            int sum=x+1,awn=len;
            int count=0,number=0;
            while(x>=0||len>0){
                if(x>=0)
            number=A[x]+K%10+count;
            else number=K%10+count;
            K=K/10;
            if(awn>sum){
            if(number>=10&&len!=1){ 
                list.add(number%10);
                count=number/10;
            }
           else if(number>=10&&len==1){
                list.add(number%10);
                list.add(number/10);
           }
            else{
                list.add(number);
                count=0;
            }
            }
            else{
                if(number>=10&&x!=0){ 
                list.add(number%10);
                count=number/10;
            }
            else if(number>=10&&x==0){
                list.add(number%10);
                list.add(number/10);
            }
            else{
                list.add(number);
                count=0;
            }
            
            }
            x--;
            len--;
            }
        Collections.reverse(list);
        return list;
    }
}
```