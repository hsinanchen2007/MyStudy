跟上题差不多，就保存上一行就行了

```
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> last = new ArrayList<>();
        for(int i=0;i<=rowIndex;i++){
            List<Integer> temp = new ArrayList<>();
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    temp.add(1);
                }else{
                    temp.add(last.get(j-1)+last.get(j));
                }
            }
            last = temp;
        }
        return last;
    }
}
```
