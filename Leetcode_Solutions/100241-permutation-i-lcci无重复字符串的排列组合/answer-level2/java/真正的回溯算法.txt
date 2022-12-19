### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //法一
   /*List<String> list=new ArrayList<>();
    public String[] permutation(String S) {
        traceBack(S.toCharArray(),0);
        return list.toArray(new String[0]);
    }

    public void traceBack(char[] arr,int first){
        if(first==arr.length-1){
            list.add(new String(arr));
            return;
        }
        for(int i=first;i<arr.length;i++){
            swap(arr,first,i);
            traceBack(arr,first+1);
            swap(arr,first,i);
        }
    }
    public void swap(char[] arr,int i,int j){
        char temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }*/
    //法二
    List<String> list=new ArrayList<>();
    public String[] permutation(String S) {
        traceBack(S,new StringBuilder());
        return list.toArray(new String[0]);
    }
    public void traceBack(String S,StringBuilder builder){
        if(S.length()==builder.length()){
            list.add(builder.toString());
            return;
        }
        for(int i=0;i<S.length();i++){
             if(builder.indexOf(String.valueOf(S.charAt(i)))>=0){
                continue;
            }
            builder.append(S.charAt(i));
            traceBack(S,builder);
            builder.deleteCharAt(builder.length()-1);
        }
    }


}
```