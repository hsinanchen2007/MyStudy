```
class Solution {
    public int[] constructArr(int[] a) {
        int len=a.length;
        int[] b=new int[len];
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<len;i++){
            if(map.containsKey(a[i])){
                b[i]=map.get(a[i]);
                continue;
            }else{
                b[i]=1;
                for(int j=0;j<len;j++){
                    if(j==i)continue;
                    b[i]*=a[j];
                }
                map.put(a[i],b[i]);
            }
        }
        return b;
    }
}
```
