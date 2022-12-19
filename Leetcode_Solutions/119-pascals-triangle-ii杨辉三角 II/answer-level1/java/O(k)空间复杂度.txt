执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
74.54%
的用户
内存消耗 :
34.2 MB
, 在所有 Java 提交中击败了
22.20%
的用户
```
class Solution {
    public List<Integer> getRow(int rowIndex) {
        rowIndex++;
        List<Integer> res = new ArrayList<Integer>();
        
        if(rowIndex==0)return res;
        res.add(1);
        if(rowIndex==1)return res;
        int j=2;
        Integer[] arr = new Integer[rowIndex];
        arr[0]=1;
        while(j<=rowIndex){
            int len = j-1;
            arr[j-1]=1;
            int last=1;
            for(int i=0; i<len; i++){
                if(i+1<len){
                    int x = last+arr[i+1];
                    last = arr[i+1];
                    arr[i+1]=x;
                }
            }
            j++;
        }
        return Arrays.asList(arr);
    }
}
```
