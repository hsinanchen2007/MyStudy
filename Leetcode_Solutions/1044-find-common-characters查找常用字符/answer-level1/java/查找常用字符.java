### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> commonChars(String[] A) {
        int number=0;
        ArrayList<String> list=new ArrayList<>();
        for(int i=0;i<A[0].length();i++){
            number=0;
            for(int j=1;j<A.length;j++){
            if(A[j].indexOf(A[0].charAt(i))!=-1){
                number++;
            }
            else break;
            }
            if(number==A.length-1){
            String sum=Character.toString(A[0].charAt(i));
            list.add(sum);  
            
            for(int j=1;j<A.length;j++){
            int h=A[j].indexOf(A[0].charAt(i));
            A[j]=A[j].substring(0,h)+A[j].substring(h+1);
            }
            }
        }
        return list;
    }
}
```