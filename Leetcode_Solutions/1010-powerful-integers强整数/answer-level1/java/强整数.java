### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        ArrayList<Integer> list=new ArrayList<>();
        for(int i=1;i<bound;i*=x){
        for(int j=1;j<bound;j*=y){
             if(!list.contains(i+j)&&i+j<=bound)
             list.add(i+j);   
             if(y==1)break;
        }
         if(x==1)break;
        }
       
       return list;
    }
}
```