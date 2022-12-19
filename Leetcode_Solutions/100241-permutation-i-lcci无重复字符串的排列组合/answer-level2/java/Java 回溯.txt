```
class Solution {
    List<String> list=new ArrayList<>();
    public String[] permutation(String S) {
        permutate(S.toCharArray(),0);
        String[] res=new String[list.size()];
        for(int i=0;i<res.length;i++){
            res[i]=list.get(i);
        }
        return res;
    }
    public void permutate(char[] arr,int first){
        if(first==arr.length-1){
            list.add(new String(arr));
            return;
        }
        for(int i=first;i<arr.length;i++){
            swap(arr,first,i);
            permutate(arr,first+1);
            swap(arr,first,i);
        }
    }
    public void swap(char[] arr,int i,int j){
        char temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
```
