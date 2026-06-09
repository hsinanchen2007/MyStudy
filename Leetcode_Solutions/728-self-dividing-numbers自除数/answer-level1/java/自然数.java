### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        ArrayList <Integer>list=new ArrayList<>();
        int number=0,count=0;
        String sum="";
      for(int i=left;i<=right;i++){
          number=0;
           if(i<10)
           list.add(i);
           else{
               sum=i+"";
               for(int j=0;j<sum.length();j++){
                   if(sum.charAt(j)-'0'!=0&&i%(sum.charAt(j)-'0')==0)
                   number++;
               }
               if(number==sum.length())
            list.add(i);
               }        
           }     
      return list;
    }
}
```